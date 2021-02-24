#include "uml/impl/ExecutableNodeImpl.hpp"

#ifdef NDEBUG
	#define DEBUG_MESSAGE(a) /**/
#else
	#define DEBUG_MESSAGE(a) a
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
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExecutableNodeImpl::ExecutableNodeImpl()
{	
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

ExecutableNodeImpl::ExecutableNodeImpl(const ExecutableNodeImpl & obj): ActivityNodeImpl(obj), ExecutableNode(obj)
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExecutableNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)

	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> handlerContainer = getHandler();
	for(auto _handler : *obj.getHandler()) 
	{
		handlerContainer->push_back(std::dynamic_pointer_cast<uml::ExceptionHandler>(_handler->copy()));
	}
	/*Subset*/
	m_handler->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
}

std::shared_ptr<ecore::EObject>  ExecutableNodeImpl::copy() const
{
	std::shared_ptr<ExecutableNodeImpl> element(new ExecutableNodeImpl(*this));
	element->setThisExecutableNodePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExecutableNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExecutableNode_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************

//*********************************
// References
//*********************************
/*
Getter & Setter for reference handler
*/
std::shared_ptr<Subset<uml::ExceptionHandler, uml::Element>> ExecutableNodeImpl::getHandler() const
{
	if(m_handler == nullptr)
	{
		/*Subset*/
		m_handler.reset(new Subset<uml::ExceptionHandler, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_handler->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_handler - Subset<uml::ExceptionHandler, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_handler;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ExecutableNodeImpl::getInGroup() const
{
	if(m_inGroup == nullptr)
	{
		/*Union*/
		m_inGroup.reset(new Union<uml::ActivityGroup>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_inGroup - Union<uml::ActivityGroup>()" << std::endl;
		#endif
		
		
	}
	return m_inGroup;
}

std::shared_ptr<Union<uml::Element>> ExecutableNodeImpl::getOwnedElement() const
{
	if(m_ownedElement == nullptr)
	{
		/*Union*/
		m_ownedElement.reset(new Union<uml::Element>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_ownedElement - Union<uml::Element>()" << std::endl;
		#endif
		
		
	}
	return m_ownedElement;
}

std::weak_ptr<uml::Element> ExecutableNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ExecutableNodeImpl::getRedefinedElement() const
{
	if(m_redefinedElement == nullptr)
	{
		/*Union*/
		m_redefinedElement.reset(new Union<uml::RedefinableElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_redefinedElement - Union<uml::RedefinableElement>()" << std::endl;
		#endif
		
		
	}
	return m_redefinedElement;
}




std::shared_ptr<ExecutableNode> ExecutableNodeImpl::getThisExecutableNodePtr() const
{
	return m_thisExecutableNodePtr.lock();
}
void ExecutableNodeImpl::setThisExecutableNodePtr(std::weak_ptr<ExecutableNode> thisExecutableNodePtr)
{
	m_thisExecutableNodePtr = thisExecutableNodePtr;
	setThisActivityNodePtr(thisExecutableNodePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any ExecutableNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
		{
			return eAny(getHandler()); //8820			
		}
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
bool ExecutableNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXECUTABLENODE_ATTRIBUTE_HANDLER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ExceptionHandler>> handlerList(new Bag<uml::ExceptionHandler>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				handlerList->add(std::dynamic_pointer_cast<uml::ExceptionHandler>(*iter));
				iter++;
			}
			
			Bag<uml::ExceptionHandler>::iterator iterHandler = m_handler->begin();
			Bag<uml::ExceptionHandler>::iterator endHandler = m_handler->end();
			while (iterHandler != endHandler)
			{
				if (handlerList->find(*iterHandler) == -1)
				{
					m_handler->erase(*iterHandler);
				}
				iterHandler++;
			}
 
			iterHandler = handlerList->begin();
			endHandler = handlerList->end();
			while (iterHandler != endHandler)
			{
				if (m_handler->find(*iterHandler) == -1)
				{
					m_handler->add(*iterHandler);
				}
				iterHandler++;			
			}
			return true;
		}
	}

	return ActivityNodeImpl::eSet(featureID, newValue);
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
				typeName = "ExceptionHandler";
			}
			loadHandler->handleChildContainer<uml::ExceptionHandler>(this->getHandler());  

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

void ExecutableNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
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
		for (std::shared_ptr<uml::ExceptionHandler> handler : *this->getHandler()) 
		{
			saveHandler->addReference(handler, "handler", handler->eClass() != package->getExceptionHandler_Class());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

