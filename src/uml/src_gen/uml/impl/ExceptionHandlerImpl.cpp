#include "uml/impl/ExceptionHandlerImpl.hpp"

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
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence

#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/Element.hpp"
#include "uml/ExecutableNode.hpp"
#include "uml/ObjectNode.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExceptionHandlerImpl::ExceptionHandlerImpl()
{	
}

ExceptionHandlerImpl::~ExceptionHandlerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExceptionHandler "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::Element> par_owner)
:ExceptionHandlerImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::ExecutableNode> par_protectedNode)
:ExceptionHandlerImpl()
{
	m_protectedNode = par_protectedNode;
	m_owner = par_protectedNode;
}

ExceptionHandlerImpl::ExceptionHandlerImpl(const ExceptionHandlerImpl & obj): ExceptionHandlerImpl()
{
	*this = obj;
}

ExceptionHandlerImpl& ExceptionHandlerImpl::operator=(const ExceptionHandlerImpl & obj)
{
	//call overloaded =Operator for each base class
	ElementImpl::operator=(obj);
	ExceptionHandler::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExceptionHandler "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_exceptionInput  = obj.getExceptionInput();
	std::shared_ptr<Bag<uml::Classifier>> _exceptionType = obj.getExceptionType();
	m_exceptionType.reset(new Bag<uml::Classifier>(*(obj.getExceptionType().get())));
	m_handlerBody  = obj.getHandlerBody();
	m_protectedNode  = obj.getProtectedNode();

	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ExceptionHandlerImpl::copy() const
{
	std::shared_ptr<ExceptionHandlerImpl> element(new ExceptionHandlerImpl());
	*element =(*this);
	element->setThisExceptionHandlerPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExceptionHandlerImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getExceptionHandler_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExceptionHandlerImpl::edge_source_target(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::exception_input_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_owner(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::one_input(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference exceptionInput
*/
std::shared_ptr<uml::ObjectNode> ExceptionHandlerImpl::getExceptionInput() const
{
//assert(m_exceptionInput);
    return m_exceptionInput;
}
void ExceptionHandlerImpl::setExceptionInput(std::shared_ptr<uml::ObjectNode> _exceptionInput)
{
    m_exceptionInput = _exceptionInput;
}


/*
Getter & Setter for reference exceptionType
*/
std::shared_ptr<Bag<uml::Classifier>> ExceptionHandlerImpl::getExceptionType() const
{
	if(m_exceptionType == nullptr)
	{
		m_exceptionType.reset(new Bag<uml::Classifier>());
		
		
	}
//assert(m_exceptionType);
    return m_exceptionType;
}



/*
Getter & Setter for reference handlerBody
*/
std::shared_ptr<uml::ExecutableNode> ExceptionHandlerImpl::getHandlerBody() const
{
//assert(m_handlerBody);
    return m_handlerBody;
}
void ExceptionHandlerImpl::setHandlerBody(std::shared_ptr<uml::ExecutableNode> _handlerBody)
{
    m_handlerBody = _handlerBody;
}


/*
Getter & Setter for reference protectedNode
*/
std::weak_ptr<uml::ExecutableNode> ExceptionHandlerImpl::getProtectedNode() const
{
//assert(m_protectedNode);
    return m_protectedNode;
}
void ExceptionHandlerImpl::setProtectedNode(std::weak_ptr<uml::ExecutableNode> _protectedNode)
{
    m_protectedNode = _protectedNode;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ExceptionHandlerImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ExceptionHandlerImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ExceptionHandler> ExceptionHandlerImpl::getThisExceptionHandlerPtr() const
{
	return m_thisExceptionHandlerPtr.lock();
}
void ExceptionHandlerImpl::setThisExceptionHandlerPtr(std::weak_ptr<ExceptionHandler> thisExceptionHandlerPtr)
{
	m_thisExceptionHandlerPtr = thisExceptionHandlerPtr;
	setThisElementPtr(thisExceptionHandlerPtr);
}
std::shared_ptr<ecore::EObject> ExceptionHandlerImpl::eContainer() const
{
	if(auto wp = m_owner.lock())
	{
		return wp;
	}

	if(auto wp = m_protectedNode.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ExceptionHandlerImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT:
			return eAny(getExceptionInput()); //873
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE:
		{
			return eAny(getExceptionType()); //874			
		}
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY:
			return eAny(getHandlerBody()); //875
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE:
			return eAny(getProtectedNode().lock()); //876
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ExceptionHandlerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT:
			return getExceptionInput() != nullptr; //873
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE:
			return getExceptionType() != nullptr; //874
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY:
			return getHandlerBody() != nullptr; //875
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE:
			return getProtectedNode().lock() != nullptr; //876
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ExceptionHandlerImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ObjectNode> _exceptionInput = std::dynamic_pointer_cast<uml::ObjectNode>(_temp);
			setExceptionInput(_exceptionInput); //873
			return true;
		}
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Classifier>> exceptionTypeList(new Bag<uml::Classifier>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				exceptionTypeList->add(std::dynamic_pointer_cast<uml::Classifier>(*iter));
				iter++;
			}
			
			Bag<uml::Classifier>::iterator iterExceptionType = m_exceptionType->begin();
			Bag<uml::Classifier>::iterator endExceptionType = m_exceptionType->end();
			while (iterExceptionType != endExceptionType)
			{
				if (exceptionTypeList->find(*iterExceptionType) == -1)
				{
					m_exceptionType->erase(*iterExceptionType);
				}
				iterExceptionType++;
			}
 
			iterExceptionType = exceptionTypeList->begin();
			endExceptionType = exceptionTypeList->end();
			while (iterExceptionType != endExceptionType)
			{
				if (m_exceptionType->find(*iterExceptionType) == -1)
				{
					m_exceptionType->add(*iterExceptionType);
				}
				iterExceptionType++;			
			}
			return true;
		}
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ExecutableNode> _handlerBody = std::dynamic_pointer_cast<uml::ExecutableNode>(_temp);
			setHandlerBody(_handlerBody); //875
			return true;
		}
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ExecutableNode> _protectedNode = std::dynamic_pointer_cast<uml::ExecutableNode>(_temp);
			setProtectedNode(_protectedNode); //876
			return true;
		}
	}

	return ElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ExceptionHandlerImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ExceptionHandlerImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("exceptionInput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("exceptionInput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("exceptionType");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("exceptionType")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("handlerBody");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("handlerBody")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ElementImpl::loadAttributes(loadHandler, attr_list);
}

void ExceptionHandlerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ElementImpl::loadNode(nodeName, loadHandler);
}

void ExceptionHandlerImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONINPUT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ObjectNode> _exceptionInput = std::dynamic_pointer_cast<uml::ObjectNode>( references.front() );
				setExceptionInput(_exceptionInput);
			}
			
			return;
		}

		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_EXCEPTIONTYPE:
		{
			std::shared_ptr<Bag<uml::Classifier>> _exceptionType = getExceptionType();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier>  _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_exceptionType->push_back(_r);
				}
			}
			return;
		}

		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_HANDLERBODY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExecutableNode> _handlerBody = std::dynamic_pointer_cast<uml::ExecutableNode>( references.front() );
				setHandlerBody(_handlerBody);
			}
			
			return;
		}

		case uml::umlPackage::EXCEPTIONHANDLER_ATTRIBUTE_PROTECTEDNODE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExecutableNode> _protectedNode = std::dynamic_pointer_cast<uml::ExecutableNode>( references.front() );
				setProtectedNode(_protectedNode);
			}
			
			return;
		}
	}
	ElementImpl::resolveReferences(featureID, references);
}

void ExceptionHandlerImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ExceptionHandlerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getExceptionInput(), "exceptionInput", getExceptionInput()->eClass() != uml::umlPackage::eInstance()->getObjectNode_Class()); 
		saveHandler->addReferences<uml::Classifier>("exceptionType", this->getExceptionType());
		saveHandler->addReference(this->getHandlerBody(), "handlerBody", getHandlerBody()->eClass() != uml::umlPackage::eInstance()->getExecutableNode_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

