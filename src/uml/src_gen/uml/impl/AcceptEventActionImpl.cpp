#include "uml/impl/AcceptEventActionImpl.hpp"

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
#include "uml/UmlFactory.hpp"


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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
AcceptEventActionImpl::AcceptEventActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

AcceptEventActionImpl::~AcceptEventActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete AcceptEventAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::Activity> par_activity)
:AcceptEventActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:AcceptEventActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:AcceptEventActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
AcceptEventActionImpl::AcceptEventActionImpl(std::weak_ptr<uml::Element> par_owner)
:AcceptEventActionImpl()
{
	m_owner = par_owner;
}

AcceptEventActionImpl::AcceptEventActionImpl(const AcceptEventActionImpl & obj): AcceptEventActionImpl()
{
	*this = obj;
}

AcceptEventActionImpl& AcceptEventActionImpl::operator=(const AcceptEventActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	AcceptEventAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy AcceptEventAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isUnmarshall = obj.getIsUnmarshall();

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> resultContainer = getResult();
	if(nullptr != resultContainer )
	{
		int size = resultContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _result=(*resultContainer)[i];
			if(nullptr != _result)
			{
				resultContainer->push_back(std::dynamic_pointer_cast<uml::OutputPin>(_result->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container result."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr result."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Trigger, uml::Element>> triggerContainer = getTrigger();
	if(nullptr != triggerContainer )
	{
		int size = triggerContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _trigger=(*triggerContainer)[i];
			if(nullptr != _trigger)
			{
				triggerContainer->push_back(std::dynamic_pointer_cast<uml::Trigger>(_trigger->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container trigger."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr trigger."<< std::endl;)
	}
	/*Subset*/
	m_result->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	/*Subset*/
	m_trigger->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> AcceptEventActionImpl::copy() const
{
	std::shared_ptr<AcceptEventActionImpl> element(new AcceptEventActionImpl());
	*element =(*this);
	element->setThisAcceptEventActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> AcceptEventActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getAcceptEventAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isUnmarshall
*/
bool AcceptEventActionImpl::getIsUnmarshall() const 
{
	return m_isUnmarshall;
}
void AcceptEventActionImpl::setIsUnmarshall(bool _isUnmarshall)
{
	m_isUnmarshall = _isUnmarshall;
} 


//*********************************
// Operations
//*********************************
bool AcceptEventActionImpl::conforming_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::no_input_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::no_output_pins(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::one_output_pin(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool AcceptEventActionImpl::unmarshall_signal_events(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference result
*/
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> AcceptEventActionImpl::getResult() const
{
	if(m_result == nullptr)
	{
		/*Subset*/
		m_result.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_result->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_result - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}

    return m_result;
}



/*
Getter & Setter for reference trigger
*/
std::shared_ptr<Subset<uml::Trigger, uml::Element>> AcceptEventActionImpl::getTrigger() const
{
	if(m_trigger == nullptr)
	{
		/*Subset*/
		m_trigger.reset(new Subset<uml::Trigger, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_trigger->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_trigger - Subset<uml::Trigger, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
//assert(m_trigger);
    return m_trigger;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> AcceptEventActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> AcceptEventActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_output->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> AcceptEventActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> AcceptEventActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> AcceptEventActionImpl::getRedefinedElement() const
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




std::shared_ptr<AcceptEventAction> AcceptEventActionImpl::getThisAcceptEventActionPtr() const
{
	return m_thisAcceptEventActionPtr.lock();
}
void AcceptEventActionImpl::setThisAcceptEventActionPtr(std::weak_ptr<AcceptEventAction> thisAcceptEventActionPtr)
{
	m_thisAcceptEventActionPtr = thisAcceptEventActionPtr;
	setThisActionPtr(thisAcceptEventActionPtr);
}
std::shared_ptr<ecore::EObject> AcceptEventActionImpl::eContainer() const
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
Any AcceptEventActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL:
			return eAny(getIsUnmarshall()); //327
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_RESULT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_result->begin();
			Bag<uml::OutputPin>::iterator end = m_result->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //328			
		}
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Trigger>::iterator iter = m_trigger->begin();
			Bag<uml::Trigger>::iterator end = m_trigger->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //329			
		}
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool AcceptEventActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL:
			return getIsUnmarshall() != false; //327
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //328
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER:
			return getTrigger() != nullptr; //329
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool AcceptEventActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_ISUNMARSHALL:
		{
			// BOOST CAST
			bool _isUnmarshall = newValue->get<bool>();
			setIsUnmarshall(_isUnmarshall); //327
			return true;
		}
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> resultList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				resultList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterResult = m_result->begin();
			Bag<uml::OutputPin>::iterator endResult = m_result->end();
			while (iterResult != endResult)
			{
				if (resultList->find(*iterResult) == -1)
				{
					m_result->erase(*iterResult);
				}
				iterResult++;
			}
 
			iterResult = resultList->begin();
			endResult = resultList->end();
			while (iterResult != endResult)
			{
				if (m_result->find(*iterResult) == -1)
				{
					m_result->add(*iterResult);
				}
				iterResult++;			
			}
			return true;
		}
		case uml::umlPackage::ACCEPTEVENTACTION_ATTRIBUTE_TRIGGER:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Trigger>> triggerList(new Bag<uml::Trigger>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				triggerList->add(std::dynamic_pointer_cast<uml::Trigger>(*iter));
				iter++;
			}
			
			Bag<uml::Trigger>::iterator iterTrigger = m_trigger->begin();
			Bag<uml::Trigger>::iterator endTrigger = m_trigger->end();
			while (iterTrigger != endTrigger)
			{
				if (triggerList->find(*iterTrigger) == -1)
				{
					m_trigger->erase(*iterTrigger);
				}
				iterTrigger++;
			}
 
			iterTrigger = triggerList->begin();
			endTrigger = triggerList->end();
			while (iterTrigger != endTrigger)
			{
				if (m_trigger->find(*iterTrigger) == -1)
				{
					m_trigger->add(*iterTrigger);
				}
				iterTrigger++;			
			}
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any AcceptEventActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 400
		case umlPackage::ACCEPTEVENTACTION_OPERATION_CONFORMING_TYPE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->conforming_type(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 397
		case umlPackage::ACCEPTEVENTACTION_OPERATION_NO_INPUT_PINS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_input_pins(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 398
		case umlPackage::ACCEPTEVENTACTION_OPERATION_NO_OUTPUT_PINS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->no_output_pins(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 396
		case umlPackage::ACCEPTEVENTACTION_OPERATION_ONE_OUTPUT_PIN_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->one_output_pin(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 399
		case umlPackage::ACCEPTEVENTACTION_OPERATION_UNMARSHALL_SIGNAL_EVENTS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->unmarshall_signal_events(incoming_param_diagnostics,incoming_param_context));
			break;
		}

		default:
		{
			// call superTypes
			result = ActionImpl::eInvoke(operationID, arguments);
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
void AcceptEventActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void AcceptEventActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isUnmarshall");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsUnmarshall(value);
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

void AcceptEventActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

		if ( nodeName.compare("trigger") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Trigger";
			}
			loadHandler->handleChildContainer<uml::Trigger>(this->getTrigger());  

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

void AcceptEventActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void AcceptEventActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void AcceptEventActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'result'
		for (std::shared_ptr<uml::OutputPin> result : *this->getResult()) 
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}

		// Save 'trigger'
		for (std::shared_ptr<uml::Trigger> trigger : *this->getTrigger()) 
		{
			saveHandler->addReference(trigger, "trigger", trigger->eClass() != package->getTrigger_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getAcceptEventAction_Attribute_isUnmarshall()) )
		{
			saveHandler->addAttribute("isUnmarshall", this->getIsUnmarshall());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

