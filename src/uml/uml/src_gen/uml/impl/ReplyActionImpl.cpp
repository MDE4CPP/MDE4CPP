
#include "uml/impl/ReplyActionImpl.hpp"
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
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"
#include "uml/Action.hpp"
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
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
#include "uml/Trigger.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReplyActionImpl::ReplyActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReplyActionImpl::~ReplyActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReplyAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ReplyActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ReplyActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ReplyActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReplyActionImpl::ReplyActionImpl(std::weak_ptr<uml::Element> par_owner)
:ReplyActionImpl()
{
	m_owner = par_owner;
}

ReplyActionImpl::ReplyActionImpl(const ReplyActionImpl & obj): ReplyActionImpl()
{
	*this = obj;
}

ReplyActionImpl& ReplyActionImpl::operator=(const ReplyActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReplyAction 
	 * which is generated by the compiler (as ReplyAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReplyAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReplyAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_replyToCall  = obj.getReplyToCall();
	//Clone references with containment (deep copy)
	//clone reference 'replyValue'
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> replyValueList = obj.getReplyValue();
	if(replyValueList)
	{
		/*Subset*/
		m_replyValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getReplyValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InputPin> replyValueindexElem: *replyValueList) 
		{
			std::shared_ptr<uml::InputPin> temp = std::dynamic_pointer_cast<uml::InputPin>((replyValueindexElem)->copy());
			m_replyValue->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for replyValue.")
	}

	//clone reference 'returnInformation'
	if(obj.getReturnInformation()!=nullptr)
	{
		m_returnInformation = std::dynamic_pointer_cast<uml::InputPin>(obj.getReturnInformation()->copy());
	}
	/*Subset*/
	getReplyValue()->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ReplyActionImpl::copy() const
{
	std::shared_ptr<ReplyActionImpl> element(new ReplyActionImpl());
	*element =(*this);
	element->setThisReplyActionPtr(element);
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
/* Getter & Setter for reference replyToCall */
const std::shared_ptr<uml::Trigger>& ReplyActionImpl::getReplyToCall() const
{
    return m_replyToCall;
}
void ReplyActionImpl::setReplyToCall(const std::shared_ptr<uml::Trigger>& _replyToCall)
{
    m_replyToCall = _replyToCall;
	
}

/* Getter & Setter for reference replyValue */
const std::shared_ptr<Subset<uml::InputPin, uml::InputPin>>& ReplyActionImpl::getReplyValue() const
{
	if(m_replyValue == nullptr)
	{
		/*Subset*/
		m_replyValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getReplyValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_replyValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}
    return m_replyValue;
}

/* Getter & Setter for reference returnInformation */
const std::shared_ptr<uml::InputPin>& ReplyActionImpl::getReturnInformation() const
{
    return m_returnInformation;
}
void ReplyActionImpl::setReturnInformation(const std::shared_ptr<uml::InputPin>& _returnInformation)
{
    m_returnInformation = _returnInformation;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReplyActionImpl::eContainer() const
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
void ReplyActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReplyActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("replyToCall");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("replyToCall")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void ReplyActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("replyValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getReplyValue());  

			return; 
		}

		if ( nodeName.compare("returnInformation") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getReturnInformation()); 

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
	ActionImpl::loadNode(nodeName, loadHandler);
}

void ReplyActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Trigger> _replyToCall = std::dynamic_pointer_cast<uml::Trigger>( references.front() );
				setReplyToCall(_replyToCall);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReplyActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActionImpl::saveContent(saveHandler);
	
	ExecutableNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ReplyActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'replyValue'
		for (std::shared_ptr<uml::InputPin> replyValue : *this->getReplyValue()) 
		{
			saveHandler->addReference(replyValue, "replyValue", replyValue->eClass() != package->getInputPin_Class());
		}

		// Save 'returnInformation'
		std::shared_ptr<uml::InputPin> returnInformation = this->getReturnInformation();
		if (returnInformation != nullptr)
		{
			saveHandler->addReference(returnInformation, "returnInformation", returnInformation->eClass() != package->getInputPin_Class());
		}
	// Add references
		saveHandler->addReference(this->getReplyToCall(), "replyToCall", getReplyToCall()->eClass() != uml::umlPackage::eInstance()->getTrigger_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ReplyActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getReplyAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ReplyActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
			return eAny(getReplyToCall(),uml::umlPackage::TRIGGER_CLASS,false); //21127
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
			return eEcoreContainerAny(getReplyValue(),uml::umlPackage::INPUTPIN_CLASS); //21128
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
			return eAny(getReturnInformation(),uml::umlPackage::INPUTPIN_CLASS,false); //21129
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool ReplyActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
			return getReplyToCall() != nullptr; //21127
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
			return getReplyValue() != nullptr; //21128
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
			return getReturnInformation() != nullptr; //21129
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool ReplyActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYTOCALL:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::Trigger> _replyToCall = std::dynamic_pointer_cast<uml::Trigger>(eObject);
					if(_replyToCall)
					{
						setReplyToCall(_replyToCall); //21127
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'replyToCall'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'replyToCall'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_REPLYVALUE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::InputPin>> _replyValue = getReplyValue();
	
						for(const std::shared_ptr<ecore::EObject> anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InputPin> valueToAdd = std::dynamic_pointer_cast<uml::InputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(_replyValue->find(valueToAdd) == -1)
								{
									_replyValue->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'replyValue'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'replyValue'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::REPLYACTION_ATTRIBUTE_RETURNINFORMATION:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::InputPin> _returnInformation = std::dynamic_pointer_cast<uml::InputPin>(eObject);
					if(_returnInformation)
					{
						setReturnInformation(_returnInformation); //21129
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'returnInformation'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'returnInformation'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ReplyActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ReplyAction> ReplyActionImpl::getThisReplyActionPtr() const
{
	return m_thisReplyActionPtr.lock();
}
void ReplyActionImpl::setThisReplyActionPtr(std::weak_ptr<uml::ReplyAction> thisReplyActionPtr)
{
	m_thisReplyActionPtr = thisReplyActionPtr;
	setThisActionPtr(thisReplyActionPtr);
}


