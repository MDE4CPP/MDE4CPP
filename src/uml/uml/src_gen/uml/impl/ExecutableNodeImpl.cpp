
#include "uml/impl/ExecutableNodeImpl.hpp"
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
#include "ecore/EReference.hpp"
#include "ecore/EStructuralFeature.hpp"
#include "ecore/ecorePackage.hpp"
#include "ecore/ecoreFactory.hpp"
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
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/ExceptionHandler.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutableNodeImpl::ExecutableNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ExecutableNodeImpl::~ExecutableNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExecutableNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:ExecutableNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ExecutableNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ExecutableNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ExecutableNodeImpl::ExecutableNodeImpl(std::weak_ptr<uml::Element> par_owner)
:ExecutableNodeImpl()
{
	m_owner = par_owner;
}

ExecutableNodeImpl::ExecutableNodeImpl(const ExecutableNodeImpl & obj): ExecutableNodeImpl()
{
	*this = obj;
}

ExecutableNodeImpl& ExecutableNodeImpl::operator=(const ExecutableNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ActivityNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ExecutableNode 
	 * which is generated by the compiler (as ExecutableNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ExecutableNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutableNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	//clone reference 'handler'
	const std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>>& handlerList = obj.getHandler();
	if(handlerList)
	{
		/*Subset*/
		m_handler.reset(new Subset<uml::ExceptionHandler, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getHandler()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
		for(const std::shared_ptr<uml::ExceptionHandler>& handlerindexElem: *handlerList) 
		{
			const std::shared_ptr<uml::ExceptionHandler>& temp = std::dynamic_pointer_cast<uml::ExceptionHandler>((handlerindexElem)->copy());
			m_handler->push_back(temp);
		}
	}
	else
	{
		DEBUG_WARNING("container is nullptr for handler.")
	}
	/*Subset*/
	getHandler()->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
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
/* Getter & Setter for reference handler */
const std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>>& ExecutableNodeImpl::getHandler() const
{
	if(m_handler == nullptr)
	{
		/*Subset*/
		m_handler.reset(new Subset<uml::ExceptionHandler, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		getHandler()->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
    return m_handler;
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ExecutableNodeImpl::eContainer() const
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
void ExecutableNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExecutableNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActivityNodeImpl::loadAttributes(loadHandler, attr_list);
}

void ExecutableNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("handler") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "uml::ExceptionHandler";
			}
			else
			{
				if (std::string::npos == typeName.find("uml/]"))
				{
					typeName = "uml::"+typeName;
				}
			}
			std::shared_ptr<ecore::ecoreFactory> modelFactory = ecore::ecoreFactory::eInstance();		
			std::shared_ptr<uml::ExceptionHandler> new_handler = std::dynamic_pointer_cast<uml::ExceptionHandler>(modelFactory->create(typeName, loadHandler->getCurrentObject(), uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER));
			if(new_handler)
			{
				loadHandler->handleChild(new_handler);
				getHandler()->push_back(new_handler);
			} 

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
	ActivityNodeImpl::loadNode(nodeName, loadHandler);
}

void ExecutableNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject>> references)
{
	ActivityNodeImpl::resolveReferences(featureID, references);
}

void ExecutableNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void ExecutableNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'handler'
		for (const std::shared_ptr<uml::ExceptionHandler>& handler : *this->getHandler()) 
		{
			saveHandler->addReference(handler, "handler", handler->eClass() != package->getExceptionHandler_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

const std::shared_ptr<ecore::EClass>& ExecutableNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExecutableNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> ExecutableNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
			return eEcoreContainerAny(getHandler(),uml::umlPackage::EXCEPTIONHANDLER_CLASS); //8820
	}
	return ActivityNodeImpl::eGet(featureID, resolve, coreType);
}

bool ExecutableNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
			return getHandler() != nullptr; //8820
	}
	return ActivityNodeImpl::internalEIsSet(featureID);
}

bool ExecutableNodeImpl::eSet(int featureID,  const std::shared_ptr<Any>& newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
		{
			std::shared_ptr<ecore::EcoreContainerAny> ecoreContainerAny = std::dynamic_pointer_cast<ecore::EcoreContainerAny>(newValue);
			if(ecoreContainerAny)
			{
				try
				{
					std::shared_ptr<Bag<ecore::EObject>> eObjectList = ecoreContainerAny->getAsEObjectContainer();
	
					if(eObjectList)
					{
						const std::shared_ptr<Bag<uml::ExceptionHandler>>& _handler = getHandler();
	
						for(const std::shared_ptr<ecore::EObject>& anEObject: *eObjectList)
						{
							std::shared_ptr<uml::ExceptionHandler> valueToAdd = std::dynamic_pointer_cast<uml::ExceptionHandler>(anEObject);
	
							if (valueToAdd)
							{
								if(!(_handler->includes(valueToAdd)))
								{
									_handler->add(valueToAdd);
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
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreContainerAny' for feature 'handler'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreContainerAny' for feature 'handler'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return ActivityNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> ExecutableNodeImpl::eInvoke(int operationID, const std::shared_ptr<Bag<Any>>& arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{

		default:
		{
			// call superTypes
			result = ActivityNodeImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::ExecutableNode> ExecutableNodeImpl::getThisExecutableNodePtr() const
{
	return m_thisExecutableNodePtr.lock();
}
void ExecutableNodeImpl::setThisExecutableNodePtr(std::weak_ptr<uml::ExecutableNode> thisExecutableNodePtr)
{
	m_thisExecutableNodePtr = thisExecutableNodePtr;
	setThisActivityNodePtr(thisExecutableNodePtr);
}


