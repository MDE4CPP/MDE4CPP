
#include "uml/impl/LinkActionImpl.hpp"
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
#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Association.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InputPin.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/LinkEndData.hpp"
#include "uml/Namespace.hpp"
#include "uml/OutputPin.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
LinkActionImpl::LinkActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

LinkActionImpl::~LinkActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete LinkAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Activity> par_activity)
:LinkActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:LinkActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:LinkActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
LinkActionImpl::LinkActionImpl(std::weak_ptr<uml::Element> par_owner)
:LinkActionImpl()
{
	m_owner = par_owner;
}

LinkActionImpl::LinkActionImpl(const LinkActionImpl & obj): LinkActionImpl()
{
	*this = obj;
}

LinkActionImpl& LinkActionImpl::operator=(const LinkActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of LinkAction 
	 * which is generated by the compiler (as LinkAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//LinkAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy LinkAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'endData'
	std::shared_ptr<Subset<uml::LinkEndData, uml::Element>> endDataList = obj.getEndData();
	if(endDataList)
	{
		/*Subset*/
		m_endData.reset(new Subset<uml::LinkEndData, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndData()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::LinkEndData>& endDataindexElem: *endDataList) 
		{
			std::shared_ptr<uml::LinkEndData> temp = std::dynamic_pointer_cast<uml::LinkEndData>((endDataindexElem)->copy());
			m_endData->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for endData.")
	}

	//clone reference 'inputValue'
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> inputValueList = obj.getInputValue();
	if(inputValueList)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getInputValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::InputPin>& inputValueindexElem: *inputValueList) 
		{
			std::shared_ptr<uml::InputPin> temp = std::dynamic_pointer_cast<uml::InputPin>((inputValueindexElem)->copy());
			m_inputValue->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for inputValue.")
	}
	/*Subset*/
	getEndData()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*Subset*/
	getInputValue()->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	return *this;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Association> LinkActionImpl::association()
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference endData */
const std::shared_ptr<Subset<uml::LinkEndData, uml::Element>>& LinkActionImpl::getEndData() const
{
	if(m_endData == nullptr)
	{
		/*Subset*/
		m_endData.reset(new Subset<uml::LinkEndData, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getEndData()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_endData - Subset<uml::LinkEndData, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_endData;
}

/* Getter & Setter for reference inputValue */
const std::shared_ptr<Subset<uml::InputPin, uml::InputPin>>& LinkActionImpl::getInputValue() const
{
	if(m_inputValue == nullptr)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		getInputValue()->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}
    return m_inputValue;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> LinkActionImpl::eContainer() const
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
void LinkActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void LinkActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void LinkActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("endData") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "LinkEndData";
			}
			loadHandler->handleChildContainer<uml::LinkEndData>(this->getEndData());  

			return; 
		}

		if ( nodeName.compare("inputValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChildContainer<uml::InputPin>(this->getInputValue());  

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

void LinkActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void LinkActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void LinkActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'endData'
		for (const std::shared_ptr<uml::LinkEndData>& endData : *this->getEndData()) 
		{
			saveHandler->addReference(endData, "endData", endData->eClass() != package->getLinkEndData_Class());
		}

		// Save 'inputValue'
		for (const std::shared_ptr<uml::InputPin>& inputValue : *this->getInputValue()) 
		{
			saveHandler->addReference(inputValue, "inputValue", inputValue->eClass() != package->getInputPin_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> LinkActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getLinkAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> LinkActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
			return eEcoreContainerAny(getEndData(),uml::umlPackage::LINKENDDATA_CLASS); //13327
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
			return eEcoreContainerAny(getInputValue(),uml::umlPackage::INPUTPIN_CLASS); //13328
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool LinkActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
			return getEndData() != nullptr; //13327
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
			return getInputValue() != nullptr; //13328
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool LinkActionImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::LINKACTION_ATTRIBUTE_ENDDATA:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::LinkEndData>> _endData = getEndData();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::LinkEndData> valueToAdd = std::dynamic_pointer_cast<uml::LinkEndData>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_endData->includes(valueToAdd)))
								{
									_endData->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'endData'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'endData'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::LINKACTION_ATTRIBUTE_INPUTVALUE:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						std::shared_ptr<Bag<uml::InputPin>> _inputValue = getInputValue();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::InputPin> valueToAdd = std::dynamic_pointer_cast<uml::InputPin>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_inputValue->includes(valueToAdd)))
								{
									_inputValue->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'inputValue'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'inputValue'. Failed to set feature!")
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
std::shared_ptr<Any> LinkActionImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::LinkAction::association() : uml::Association: 4091876769
		case umlPackage::LINKACTION_OPERATION_ASSOCIATION:
		{
			result = eEcoreAny(this->association(), uml::umlPackage::ASSOCIATION_CLASS);
			break;
		}

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

std::shared_ptr<uml::LinkAction> LinkActionImpl::getThisLinkActionPtr() const
{
	return m_thisLinkActionPtr.lock();
}
void LinkActionImpl::setThisLinkActionPtr(std::weak_ptr<uml::LinkAction> thisLinkActionPtr)
{
	m_thisLinkActionPtr = thisLinkActionPtr;
	setThisActionPtr(thisLinkActionPtr);
}


