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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Classifier.hpp"

#include "uml/Comment.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/ExecutableNode.hpp"

#include "uml/ObjectNode.hpp"

#include "ecore/EcorePackage.hpp"
#include "ecore/EcoreFactory.hpp"
#include "uml/UmlPackage.hpp"
#include "uml/UmlFactory.hpp"
#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ExceptionHandlerImpl::ExceptionHandlerImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_exceptionType.reset(new Bag<uml::Classifier>());
	
	

	

	

	//Init references
	

	
	

	

	
}

ExceptionHandlerImpl::~ExceptionHandlerImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ExceptionHandler "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::Element > par_owner)
			:ExceptionHandlerImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			ExceptionHandlerImpl::ExceptionHandlerImpl(std::weak_ptr<uml::ExecutableNode > par_protectedNode)
			:ExceptionHandlerImpl()
			{
			    m_protectedNode = par_protectedNode;
				m_owner = par_protectedNode;
			}






ExceptionHandlerImpl::ExceptionHandlerImpl(const ExceptionHandlerImpl & obj):ExceptionHandlerImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ExceptionHandler "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif

	//copy references with no containment (soft copy)
	
	m_exceptionInput  = obj.getExceptionInput();

	std::shared_ptr<Bag<uml::Classifier>> _exceptionType = obj.getExceptionType();
	m_exceptionType.reset(new Bag<uml::Classifier>(*(obj.getExceptionType().get())));

	m_handlerBody  = obj.getHandlerBody();

	m_owner  = obj.getOwner();

	m_protectedNode  = obj.getProtectedNode();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif

}

std::shared_ptr<ecore::EObject>  ExceptionHandlerImpl::copy() const
{
	std::shared_ptr<ExceptionHandlerImpl> element(new ExceptionHandlerImpl(*this));
	element->setThisExceptionHandlerPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ExceptionHandlerImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getExceptionHandler_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ExceptionHandlerImpl::edge_source_target(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::exception_input_type(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_edges(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::handler_body_owner(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::one_input(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ExceptionHandlerImpl::output_pins(Any diagnostics,std::map <   Any, Any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::ObjectNode > ExceptionHandlerImpl::getExceptionInput() const
{
//assert(m_exceptionInput);
    return m_exceptionInput;
}
void ExceptionHandlerImpl::setExceptionInput(std::shared_ptr<uml::ObjectNode> _exceptionInput)
{
    m_exceptionInput = _exceptionInput;
}

std::shared_ptr<Bag<uml::Classifier>> ExceptionHandlerImpl::getExceptionType() const
{
//assert(m_exceptionType);
    return m_exceptionType;
}


std::shared_ptr<uml::ExecutableNode > ExceptionHandlerImpl::getHandlerBody() const
{
//assert(m_handlerBody);
    return m_handlerBody;
}
void ExceptionHandlerImpl::setHandlerBody(std::shared_ptr<uml::ExecutableNode> _handlerBody)
{
    m_handlerBody = _handlerBody;
}

std::weak_ptr<uml::ExecutableNode > ExceptionHandlerImpl::getProtectedNode() const
{
//assert(m_protectedNode);
    return m_protectedNode;
}
void ExceptionHandlerImpl::setProtectedNode(std::shared_ptr<uml::ExecutableNode> _protectedNode)
{
    m_protectedNode = _protectedNode;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ExceptionHandlerImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ExceptionHandlerImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ExceptionHandler> ExceptionHandlerImpl::getThisExceptionHandlerPtr()
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
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
			return eAny(getExceptionInput()); //1154
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONTYPE:
			return eAny(getExceptionType()); //1155
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
			return eAny(getHandlerBody()); //1156
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
			return eAny(getProtectedNode()); //1157
	}
	return ElementImpl::eGet(featureID, resolve, coreType);
}
bool ExceptionHandlerImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
			return getExceptionInput() != nullptr; //1154
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONTYPE:
			return getExceptionType() != nullptr; //1155
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
			return getHandlerBody() != nullptr; //1156
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
			return getProtectedNode().lock() != nullptr; //1157
	}
	return ElementImpl::internalEIsSet(featureID);
}
bool ExceptionHandlerImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
		{
			// BOOST CAST
			std::shared_ptr<uml::ObjectNode> _exceptionInput = newValue->get<std::shared_ptr<uml::ObjectNode>>();
			setExceptionInput(_exceptionInput); //1154
			return true;
		}
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
		{
			// BOOST CAST
			std::shared_ptr<uml::ExecutableNode> _handlerBody = newValue->get<std::shared_ptr<uml::ExecutableNode>>();
			setHandlerBody(_handlerBody); //1156
			return true;
		}
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
		{
			// BOOST CAST
			std::shared_ptr<uml::ExecutableNode> _protectedNode = newValue->get<std::shared_ptr<uml::ExecutableNode>>();
			setProtectedNode(_protectedNode); //1157
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ExceptionHandlerImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	ElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ExceptionHandlerImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONINPUT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ObjectNode> _exceptionInput = std::dynamic_pointer_cast<uml::ObjectNode>( references.front() );
				setExceptionInput(_exceptionInput);
			}
			
			return;
		}

		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_EXCEPTIONTYPE:
		{
			std::shared_ptr<Bag<uml::Classifier>> _exceptionType = getExceptionType();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Classifier> _r = std::dynamic_pointer_cast<uml::Classifier>(ref);
				if (_r != nullptr)
				{
					_exceptionType->push_back(_r);
				}				
			}
			return;
		}

		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_HANDLERBODY:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ExecutableNode> _handlerBody = std::dynamic_pointer_cast<uml::ExecutableNode>( references.front() );
				setHandlerBody(_handlerBody);
			}
			
			return;
		}

		case UmlPackage::EXCEPTIONHANDLER_EREFERENCE_PROTECTEDNODE:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
}

void ExceptionHandlerImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		saveHandler->addReference("exceptionInput", this->getExceptionInput());
		std::shared_ptr<Bag<uml::Classifier>> exceptionType_list = this->getExceptionType();
		for (std::shared_ptr<uml::Classifier > object : *exceptionType_list)
		{ 
			saveHandler->addReferences("exceptionType", object);
		}
		saveHandler->addReference("handlerBody", this->getHandlerBody());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

