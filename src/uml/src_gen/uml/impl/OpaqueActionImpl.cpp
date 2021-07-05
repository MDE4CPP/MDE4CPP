#include "uml/impl/OpaqueActionImpl.hpp"

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
OpaqueActionImpl::OpaqueActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

OpaqueActionImpl::~OpaqueActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete OpaqueAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Activity> par_activity)
:OpaqueActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:OpaqueActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:OpaqueActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
OpaqueActionImpl::OpaqueActionImpl(std::weak_ptr<uml::Element> par_owner)
:OpaqueActionImpl()
{
	m_owner = par_owner;
}

OpaqueActionImpl::OpaqueActionImpl(const OpaqueActionImpl & obj): OpaqueActionImpl()
{
	*this = obj;
}

OpaqueActionImpl& OpaqueActionImpl::operator=(const OpaqueActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	OpaqueAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy OpaqueAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	std::shared_ptr<Bag<std::string>> bodyContainer = getBody();
	if(nullptr != bodyContainer )
	{
		int size = bodyContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _body=(*bodyContainer)[i];	
			if(nullptr != _body)
			{
				bodyContainer->push_back(_body);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container body."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr body."<< std::endl;)
	}
	std::shared_ptr<Bag<std::string>> languageContainer = getLanguage();
	if(nullptr != languageContainer )
	{
		int size = languageContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _language=(*languageContainer)[i];	
			if(nullptr != _language)
			{
				languageContainer->push_back(_language);
			} 
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container language."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr language."<< std::endl;)
	}

	//copy references with no containment (soft copy)
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> inputValueContainer = getInputValue();
	if(nullptr != inputValueContainer )
	{
		int size = inputValueContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _inputValue=(*inputValueContainer)[i];
			if(nullptr != _inputValue)
			{
				inputValueContainer->push_back(std::dynamic_pointer_cast<uml::InputPin>(_inputValue->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container inputValue."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr inputValue."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> outputValueContainer = getOutputValue();
	if(nullptr != outputValueContainer )
	{
		int size = outputValueContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _outputValue=(*outputValueContainer)[i];
			if(nullptr != _outputValue)
			{
				outputValueContainer->push_back(std::dynamic_pointer_cast<uml::OutputPin>(_outputValue->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container outputValue."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr outputValue."<< std::endl;)
	}
	/*Subset*/
	m_inputValue->initSubset(getInput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
	#endif
	
	/*Subset*/
	m_outputValue->initSubset(getOutput());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> OpaqueActionImpl::copy() const
{
	std::shared_ptr<OpaqueActionImpl> element(new OpaqueActionImpl());
	*element =(*this);
	element->setThisOpaqueActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> OpaqueActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getOpaqueAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute body
*/
std::shared_ptr<Bag<std::string>> OpaqueActionImpl::getBody() const 
{
	if(m_body == nullptr)
	{
		m_body.reset(new Bag<std::string>());
	}
	return m_body;
}



/*
Getter & Setter for attribute language
*/
std::shared_ptr<Bag<std::string>> OpaqueActionImpl::getLanguage() const 
{
	if(m_language == nullptr)
	{
		m_language.reset(new Bag<std::string>());
	}
	return m_language;
}



//*********************************
// Operations
//*********************************
bool OpaqueActionImpl::language_body_size(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference inputValue
*/
std::shared_ptr<Subset<uml::InputPin, uml::InputPin>> OpaqueActionImpl::getInputValue() const
{
	if(m_inputValue == nullptr)
	{
		/*Subset*/
		m_inputValue.reset(new Subset<uml::InputPin, uml::InputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_inputValue->initSubset(getInput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_inputValue - Subset<uml::InputPin, uml::InputPin >(getInput())" << std::endl;
		#endif
		
	}

    return m_inputValue;
}



/*
Getter & Setter for reference outputValue
*/
std::shared_ptr<Subset<uml::OutputPin, uml::OutputPin>> OpaqueActionImpl::getOutputValue() const
{
	if(m_outputValue == nullptr)
	{
		/*Subset*/
		m_outputValue.reset(new Subset<uml::OutputPin, uml::OutputPin >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >()" << std::endl;
		#endif
		
		/*Subset*/
		m_outputValue->initSubset(getOutput());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_outputValue - Subset<uml::OutputPin, uml::OutputPin >(getOutput())" << std::endl;
		#endif
		
	}

    return m_outputValue;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> OpaqueActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> OpaqueActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_input->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> OpaqueActionImpl::getOutput() const
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

std::shared_ptr<Union<uml::Element>> OpaqueActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> OpaqueActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> OpaqueActionImpl::getRedefinedElement() const
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




std::shared_ptr<OpaqueAction> OpaqueActionImpl::getThisOpaqueActionPtr() const
{
	return m_thisOpaqueActionPtr.lock();
}
void OpaqueActionImpl::setThisOpaqueActionPtr(std::weak_ptr<OpaqueAction> thisOpaqueActionPtr)
{
	m_thisOpaqueActionPtr = thisOpaqueActionPtr;
	setThisActionPtr(thisOpaqueActionPtr);
}
std::shared_ptr<ecore::EObject> OpaqueActionImpl::eContainer() const
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
Any OpaqueActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
			return eAny(getBody()); //16427
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::InputPin>::iterator iter = m_inputValue->begin();
			Bag<uml::InputPin>::iterator end = m_inputValue->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16428			
		}
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
			return eAny(getLanguage()); //16429
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::OutputPin>::iterator iter = m_outputValue->begin();
			Bag<uml::OutputPin>::iterator end = m_outputValue->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //16430			
		}
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool OpaqueActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
			return !getBody()->empty(); //16427
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
			return getInputValue() != nullptr; //16428
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
			return !getLanguage()->empty(); //16429
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
			return getOutputValue() != nullptr; //16430
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool OpaqueActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_BODY:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_INPUTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::InputPin>> inputValueList(new Bag<uml::InputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				inputValueList->add(std::dynamic_pointer_cast<uml::InputPin>(*iter));
				iter++;
			}
			
			Bag<uml::InputPin>::iterator iterInputValue = m_inputValue->begin();
			Bag<uml::InputPin>::iterator endInputValue = m_inputValue->end();
			while (iterInputValue != endInputValue)
			{
				if (inputValueList->find(*iterInputValue) == -1)
				{
					m_inputValue->erase(*iterInputValue);
				}
				iterInputValue++;
			}
 
			iterInputValue = inputValueList->begin();
			endInputValue = inputValueList->end();
			while (iterInputValue != endInputValue)
			{
				if (m_inputValue->find(*iterInputValue) == -1)
				{
					m_inputValue->add(*iterInputValue);
				}
				iterInputValue++;			
			}
			return true;
		}
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_LANGUAGE:
		{
			// BOOST CAST
			// nothing to do
			return true;
		}
		case uml::umlPackage::OPAQUEACTION_ATTRIBUTE_OUTPUTVALUE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::OutputPin>> outputValueList(new Bag<uml::OutputPin>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				outputValueList->add(std::dynamic_pointer_cast<uml::OutputPin>(*iter));
				iter++;
			}
			
			Bag<uml::OutputPin>::iterator iterOutputValue = m_outputValue->begin();
			Bag<uml::OutputPin>::iterator endOutputValue = m_outputValue->end();
			while (iterOutputValue != endOutputValue)
			{
				if (outputValueList->find(*iterOutputValue) == -1)
				{
					m_outputValue->erase(*iterOutputValue);
				}
				iterOutputValue++;
			}
 
			iterOutputValue = outputValueList->begin();
			endOutputValue = outputValueList->end();
			while (iterOutputValue != endOutputValue)
			{
				if (m_outputValue->find(*iterOutputValue) == -1)
				{
					m_outputValue->add(*iterOutputValue);
				}
				iterOutputValue++;			
			}
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any OpaqueActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 16497
		case umlPackage::OPAQUEACTION_OPERATION_LANGUAGE_BODY_SIZE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->language_body_size(incoming_param_diagnostics,incoming_param_context));
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
void OpaqueActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void OpaqueActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	ActionImpl::loadAttributes(loadHandler, attr_list);
}

void OpaqueActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	try
	{
		if (nodeName.compare("body") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_body = this->getBody();
			list_body->push_back(value);
			return;
		}

		if (nodeName.compare("language") == 0)
		{
			std::shared_ptr<std::string> value = loadHandler->getChildText();
			std::shared_ptr<Bag<std::string>> list_language = this->getLanguage();
			list_language->push_back(value);
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

	try
	{
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

		if ( nodeName.compare("outputValue") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChildContainer<uml::OutputPin>(this->getOutputValue());  

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

void OpaqueActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	ActionImpl::resolveReferences(featureID, references);
}

void OpaqueActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void OpaqueActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'inputValue'
		for (std::shared_ptr<uml::InputPin> inputValue : *this->getInputValue()) 
		{
			saveHandler->addReference(inputValue, "inputValue", inputValue->eClass() != package->getInputPin_Class());
		}

		// Save 'outputValue'
		for (std::shared_ptr<uml::OutputPin> outputValue : *this->getOutputValue()) 
		{
			saveHandler->addReference(outputValue, "outputValue", outputValue->eClass() != package->getOutputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getOpaqueAction_Attribute_body()) )
		{
			for (std::shared_ptr<std::string> value : *m_body)
			{
				saveHandler->addAttributeAsNode("body", *value);
			}
		}

		if ( this->eIsSet(package->getOpaqueAction_Attribute_language()) )
		{
			for (std::shared_ptr<std::string> value : *m_language)
			{
				saveHandler->addAttributeAsNode("language", *value);
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

