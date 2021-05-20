#include "uml/impl/ReduceActionImpl.hpp"

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

#include "uml/Action.hpp"
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Behavior.hpp"
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
ReduceActionImpl::ReduceActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReduceActionImpl::~ReduceActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReduceAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ReduceActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ReduceActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ReduceActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReduceActionImpl::ReduceActionImpl(std::weak_ptr<uml::Element> par_owner)
:ReduceActionImpl()
{
	m_owner = par_owner;
}

ReduceActionImpl::ReduceActionImpl(const ReduceActionImpl & obj): ReduceActionImpl()
{
	*this = obj;
}

ReduceActionImpl& ReduceActionImpl::operator=(const ReduceActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	ReduceAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReduceAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isOrdered = obj.getIsOrdered();

	//copy references with no containment (soft copy)
	m_reducer  = obj.getReducer();
	//Clone references with containment (deep copy)
	if(obj.getCollection()!=nullptr)
	{
		m_collection = std::dynamic_pointer_cast<uml::InputPin>(obj.getCollection()->copy());
	}
	if(obj.getResult()!=nullptr)
	{
		m_result = std::dynamic_pointer_cast<uml::OutputPin>(obj.getResult()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ReduceActionImpl::copy() const
{
	std::shared_ptr<ReduceActionImpl> element(new ReduceActionImpl());
	*element =(*this);
	element->setThisReduceActionPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ReduceActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getReduceAction_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute isOrdered
*/
bool ReduceActionImpl::getIsOrdered() const 
{
	return m_isOrdered;
}
void ReduceActionImpl::setIsOrdered(bool _isOrdered)
{
	m_isOrdered = _isOrdered;
} 


//*********************************
// Operations
//*********************************
bool ReduceActionImpl::input_type_is_collection(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReduceActionImpl::output_types_are_compatible(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ReduceActionImpl::reducer_inputs_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference collection
*/
std::shared_ptr<uml::InputPin> ReduceActionImpl::getCollection() const
{
//assert(m_collection);
    return m_collection;
}
void ReduceActionImpl::setCollection(std::shared_ptr<uml::InputPin> _collection)
{
    m_collection = _collection;
}


/*
Getter & Setter for reference reducer
*/
std::shared_ptr<uml::Behavior> ReduceActionImpl::getReducer() const
{
//assert(m_reducer);
    return m_reducer;
}
void ReduceActionImpl::setReducer(std::shared_ptr<uml::Behavior> _reducer)
{
    m_reducer = _reducer;
}


/*
Getter & Setter for reference result
*/
std::shared_ptr<uml::OutputPin> ReduceActionImpl::getResult() const
{
//assert(m_result);
    return m_result;
}
void ReduceActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ReduceActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ReduceActionImpl::getInput() const
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

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ReduceActionImpl::getOutput() const
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

std::shared_ptr<Union<uml::Element>> ReduceActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ReduceActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ReduceActionImpl::getRedefinedElement() const
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




std::shared_ptr<ReduceAction> ReduceActionImpl::getThisReduceActionPtr() const
{
	return m_thisReduceActionPtr.lock();
}
void ReduceActionImpl::setThisReduceActionPtr(std::weak_ptr<ReduceAction> thisReduceActionPtr)
{
	m_thisReduceActionPtr = thisReduceActionPtr;
	setThisActionPtr(thisReduceActionPtr);
}
std::shared_ptr<ecore::EObject> ReduceActionImpl::eContainer() const
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
Any ReduceActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_COLLECTION:
			return eAny(getCollection()); //20627
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_ISORDERED:
			return eAny(getIsOrdered()); //20628
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_REDUCER:
			return eAny(getReducer()); //20629
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_RESULT:
			return eAny(getResult()); //20630
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}
bool ReduceActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_COLLECTION:
			return getCollection() != nullptr; //20627
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_ISORDERED:
			return getIsOrdered() != false; //20628
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_REDUCER:
			return getReducer() != nullptr; //20629
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //20630
	}
	return ActionImpl::internalEIsSet(featureID);
}
bool ReduceActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_COLLECTION:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _collection = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setCollection(_collection); //20627
			return true;
		}
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_ISORDERED:
		{
			// BOOST CAST
			bool _isOrdered = newValue->get<bool>();
			setIsOrdered(_isOrdered); //20628
			return true;
		}
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_REDUCER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _reducer = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setReducer(_reducer); //20629
			return true;
		}
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_RESULT:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OutputPin> _result = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
			setResult(_result); //20630
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// Behavioral Feature
//*********************************
Any ReduceActionImpl::eInvoke(int operationID, std::shared_ptr<std::list < std::shared_ptr<Any>>> arguments)
{
	Any result;

  	switch(operationID)
	{
		
		// 20698
		case umlPackage::REDUCEACTION_OPERATION_INPUT_TYPE_IS_COLLECTION_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->input_type_is_collection(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20699
		case umlPackage::REDUCEACTION_OPERATION_OUTPUT_TYPES_ARE_COMPATIBLE_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->output_types_are_compatible(incoming_param_diagnostics,incoming_param_context));
			break;
		}
		
		// 20697
		case umlPackage::REDUCEACTION_OPERATION_REDUCER_INPUTS_OUTPUT_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->reducer_inputs_output(incoming_param_diagnostics,incoming_param_context));
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
void ReduceActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReduceActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isOrdered");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsOrdered(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("reducer");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("reducer")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReduceActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("collection") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getCollection()); 

			return; 
		}

		if ( nodeName.compare("result") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "OutputPin";
			}
			loadHandler->handleChild(this->getResult()); 

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

void ReduceActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::REDUCEACTION_ATTRIBUTE_REDUCER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _reducer = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setReducer(_reducer);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReduceActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ReduceActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'collection'
		std::shared_ptr<uml::InputPin> collection = this->getCollection();
		if (collection != nullptr)
		{
			saveHandler->addReference(collection, "collection", collection->eClass() != package->getInputPin_Class());
		}

		// Save 'result'
		std::shared_ptr<uml::OutputPin> result = this->getResult();
		if (result != nullptr)
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getReduceAction_Attribute_isOrdered()) )
		{
			saveHandler->addAttribute("isOrdered", this->getIsOrdered());
		}
	// Add references
		saveHandler->addReference(this->getReducer(), "reducer", getReducer()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

