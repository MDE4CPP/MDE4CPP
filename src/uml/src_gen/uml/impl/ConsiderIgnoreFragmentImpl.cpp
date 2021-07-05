#include "uml/impl/ConsiderIgnoreFragmentImpl.hpp"

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
#include "abstractDataTypes/Any.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "ecore/EAnnotation.hpp"
#include "ecore/EClass.hpp"

//Includes from codegen annotation

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence

#include <exception> // used in Persistence
#include "uml/umlFactory.hpp"


#include "uml/CombinedFragment.hpp"
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Gate.hpp"
#include "uml/GeneralOrdering.hpp"
#include "uml/Interaction.hpp"
#include "uml/InteractionOperand.hpp"
#include "uml/Lifeline.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/StringExpression.hpp"

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ConsiderIgnoreFragmentImpl::~ConsiderIgnoreFragmentImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConsiderIgnoreFragment "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Interaction> par_enclosingInteraction)
:ConsiderIgnoreFragmentImpl()
{
	m_enclosingInteraction = par_enclosingInteraction;
	m_namespace = par_enclosingInteraction;
}

//Additional constructor for the containments back reference
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::InteractionOperand> par_enclosingOperand)
:ConsiderIgnoreFragmentImpl()
{
	m_enclosingOperand = par_enclosingOperand;
	m_namespace = par_enclosingOperand;
}

//Additional constructor for the containments back reference
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ConsiderIgnoreFragmentImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(std::weak_ptr<uml::Element> par_owner)
:ConsiderIgnoreFragmentImpl()
{
	m_owner = par_owner;
}

ConsiderIgnoreFragmentImpl::ConsiderIgnoreFragmentImpl(const ConsiderIgnoreFragmentImpl & obj): ConsiderIgnoreFragmentImpl()
{
	*this = obj;
}

ConsiderIgnoreFragmentImpl& ConsiderIgnoreFragmentImpl::operator=(const ConsiderIgnoreFragmentImpl & obj)
{
	//call overloaded =Operator for each base class
	CombinedFragmentImpl::operator=(obj);
	ConsiderIgnoreFragment::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConsiderIgnoreFragment "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	std::shared_ptr<Bag<uml::NamedElement>> _message = obj.getMessage();
	m_message.reset(new Bag<uml::NamedElement>(*(obj.getMessage().get())));
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> ConsiderIgnoreFragmentImpl::copy() const
{
	std::shared_ptr<ConsiderIgnoreFragmentImpl> element(new ConsiderIgnoreFragmentImpl());
	*element =(*this);
	element->setThisConsiderIgnoreFragmentPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConsiderIgnoreFragmentImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getConsiderIgnoreFragment_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ConsiderIgnoreFragmentImpl::consider_or_ignore(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConsiderIgnoreFragmentImpl::type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference message
*/
std::shared_ptr<Bag<uml::NamedElement>> ConsiderIgnoreFragmentImpl::getMessage() const
{
	if(m_message == nullptr)
	{
		m_message.reset(new Bag<uml::NamedElement>());
		
		
	}

    return m_message;
}



//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace> ConsiderIgnoreFragmentImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConsiderIgnoreFragmentImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ConsiderIgnoreFragmentImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ConsiderIgnoreFragment> ConsiderIgnoreFragmentImpl::getThisConsiderIgnoreFragmentPtr() const
{
	return m_thisConsiderIgnoreFragmentPtr.lock();
}
void ConsiderIgnoreFragmentImpl::setThisConsiderIgnoreFragmentPtr(std::weak_ptr<ConsiderIgnoreFragment> thisConsiderIgnoreFragmentPtr)
{
	m_thisConsiderIgnoreFragmentPtr = thisConsiderIgnoreFragmentPtr;
	setThisCombinedFragmentPtr(thisConsiderIgnoreFragmentPtr);
}
std::shared_ptr<ecore::EObject> ConsiderIgnoreFragmentImpl::eContainer() const
{
	if(auto wp = m_enclosingInteraction.lock())
	{
		return wp;
	}

	if(auto wp = m_enclosingOperand.lock())
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
Any ConsiderIgnoreFragmentImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::NamedElement>::iterator iter = m_message->begin();
			Bag<uml::NamedElement>::iterator end = m_message->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5616			
		}
	}
	return CombinedFragmentImpl::eGet(featureID, resolve, coreType);
}
bool ConsiderIgnoreFragmentImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE:
			return getMessage() != nullptr; //5616
	}
	return CombinedFragmentImpl::internalEIsSet(featureID);
}
bool ConsiderIgnoreFragmentImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::NamedElement>> messageList(new Bag<uml::NamedElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				messageList->add(std::dynamic_pointer_cast<uml::NamedElement>(*iter));
				iter++;
			}
			
			Bag<uml::NamedElement>::iterator iterMessage = m_message->begin();
			Bag<uml::NamedElement>::iterator endMessage = m_message->end();
			while (iterMessage != endMessage)
			{
				if (messageList->find(*iterMessage) == -1)
				{
					m_message->erase(*iterMessage);
				}
				iterMessage++;
			}
 
			iterMessage = messageList->begin();
			endMessage = messageList->end();
			while (iterMessage != endMessage)
			{
				if (m_message->find(*iterMessage) == -1)
				{
					m_message->add(*iterMessage);
				}
				iterMessage++;			
			}
			return true;
		}
	}

	return CombinedFragmentImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ConsiderIgnoreFragmentImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 5676
		case umlPackage::CONSIDERIGNOREFRAGMENT_OPERATION_CONSIDER_OR_IGNORE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->consider_or_ignore(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 5677
		case umlPackage::CONSIDERIGNOREFRAGMENT_OPERATION_TYPE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get()->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<std::shared_ptr<Any>>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get()->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->type(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = CombinedFragmentImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

//*********************************
// Persistence Functions
//*********************************
void ConsiderIgnoreFragmentImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ConsiderIgnoreFragmentImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("message");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("message")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	CombinedFragmentImpl::loadAttributes(loadHandler, attr_list);
}

void ConsiderIgnoreFragmentImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	CombinedFragmentImpl::loadNode(nodeName, loadHandler);
}

void ConsiderIgnoreFragmentImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::CONSIDERIGNOREFRAGMENT_ATTRIBUTE_MESSAGE:
		{
			std::shared_ptr<Bag<uml::NamedElement>> _message = getMessage();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::NamedElement>  _r = std::dynamic_pointer_cast<uml::NamedElement>(ref);
				if (_r != nullptr)
				{
					_message->push_back(_r);
				}
			}
			return;
		}
	}
	CombinedFragmentImpl::resolveReferences(featureID, references);
}

void ConsiderIgnoreFragmentImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	CombinedFragmentImpl::saveContent(saveHandler);
	
	InteractionFragmentImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
	
}

void ConsiderIgnoreFragmentImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReferences<uml::NamedElement>("message", this->getMessage());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

