
#include "uml/impl/ReadIsClassifiedObjectActionImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "abstractDataTypes/AnyEObject.hpp"
#include "abstractDataTypes/AnyEObjectBag.hpp"
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
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

ReadIsClassifiedObjectActionImpl::~ReadIsClassifiedObjectActionImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ReadIsClassifiedObjectAction "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Activity> par_activity)
:ReadIsClassifiedObjectActionImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:ReadIsClassifiedObjectActionImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Namespace> par_namespace)
:ReadIsClassifiedObjectActionImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl(std::weak_ptr<uml::Element> par_owner)
:ReadIsClassifiedObjectActionImpl()
{
	m_owner = par_owner;
}

ReadIsClassifiedObjectActionImpl::ReadIsClassifiedObjectActionImpl(const ReadIsClassifiedObjectActionImpl & obj): ReadIsClassifiedObjectActionImpl()
{
	*this = obj;
}

ReadIsClassifiedObjectActionImpl& ReadIsClassifiedObjectActionImpl::operator=(const ReadIsClassifiedObjectActionImpl & obj)
{
	//call overloaded =Operator for each base class
	ActionImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of ReadIsClassifiedObjectAction 
	 * which is generated by the compiler (as ReadIsClassifiedObjectAction is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//ReadIsClassifiedObjectAction::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ReadIsClassifiedObjectAction "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_isDirect = obj.getIsDirect();

	//copy references with no containment (soft copy)
	m_classifier  = obj.getClassifier();
	//Clone references with containment (deep copy)
	//clone reference 'object'
	if(obj.getObject()!=nullptr)
	{
		m_object = std::dynamic_pointer_cast<uml::InputPin>(obj.getObject()->copy());
	}

	//clone reference 'result'
	if(obj.getResult()!=nullptr)
	{
		m_result = std::dynamic_pointer_cast<uml::OutputPin>(obj.getResult()->copy());
	}
	
	
	return *this;
}

std::shared_ptr<ecore::EObject> ReadIsClassifiedObjectActionImpl::copy() const
{
	std::shared_ptr<ReadIsClassifiedObjectActionImpl> element(new ReadIsClassifiedObjectActionImpl());
	*element =(*this);
	element->setThisReadIsClassifiedObjectActionPtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool ReadIsClassifiedObjectActionImpl::boolean_result(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ReadIsClassifiedObjectActionImpl::multiplicity_of_input(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ReadIsClassifiedObjectActionImpl::multiplicity_of_output(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool ReadIsClassifiedObjectActionImpl::no_type(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute isDirect */
bool ReadIsClassifiedObjectActionImpl::getIsDirect() const 
{
	return m_isDirect;
}
void ReadIsClassifiedObjectActionImpl::setIsDirect(bool _isDirect)
{
	m_isDirect = _isDirect;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference classifier */
std::shared_ptr<uml::Classifier> ReadIsClassifiedObjectActionImpl::getClassifier() const
{
    return m_classifier;
}
void ReadIsClassifiedObjectActionImpl::setClassifier(std::shared_ptr<uml::Classifier> _classifier)
{
    m_classifier = _classifier;
	
}

/* Getter & Setter for reference object */
std::shared_ptr<uml::InputPin> ReadIsClassifiedObjectActionImpl::getObject() const
{
    return m_object;
}
void ReadIsClassifiedObjectActionImpl::setObject(std::shared_ptr<uml::InputPin> _object)
{
    m_object = _object;
	
}

/* Getter & Setter for reference result */
std::shared_ptr<uml::OutputPin> ReadIsClassifiedObjectActionImpl::getResult() const
{
    return m_result;
}
void ReadIsClassifiedObjectActionImpl::setResult(std::shared_ptr<uml::OutputPin> _result)
{
    m_result = _result;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> ReadIsClassifiedObjectActionImpl::getInGroup() const
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

std::shared_ptr<SubsetUnion<uml::InputPin, uml::Element>> ReadIsClassifiedObjectActionImpl::getInput() const
{
	if(m_input == nullptr)
	{
		/*SubsetUnion*/
		m_input.reset(new SubsetUnion<uml::InputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getInput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_input - SubsetUnion<uml::InputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_input;
}

std::shared_ptr<SubsetUnion<uml::OutputPin, uml::Element>> ReadIsClassifiedObjectActionImpl::getOutput() const
{
	if(m_output == nullptr)
	{
		/*SubsetUnion*/
		m_output.reset(new SubsetUnion<uml::OutputPin, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		getOutput()->initSubsetUnion(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_output - SubsetUnion<uml::OutputPin, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}
	return m_output;
}

std::shared_ptr<Union<uml::Element>> ReadIsClassifiedObjectActionImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> ReadIsClassifiedObjectActionImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> ReadIsClassifiedObjectActionImpl::getRedefinedElement() const
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

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> ReadIsClassifiedObjectActionImpl::eContainer() const
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
void ReadIsClassifiedObjectActionImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ReadIsClassifiedObjectActionImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("isDirect");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'bool'
			bool value;
			std::istringstream(iter->second) >> std::boolalpha >> value;
			this->setIsDirect(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("classifier");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("classifier")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ReadIsClassifiedObjectActionImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("object") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "InputPin";
			}
			loadHandler->handleChild(this->getObject()); 

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

void ReadIsClassifiedObjectActionImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>( references.front() );
				setClassifier(_classifier);
			}
			
			return;
		}
	}
	ActionImpl::resolveReferences(featureID, references);
}

void ReadIsClassifiedObjectActionImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
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

void ReadIsClassifiedObjectActionImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'object'
		std::shared_ptr<uml::InputPin> object = this->getObject();
		if (object != nullptr)
		{
			saveHandler->addReference(object, "object", object->eClass() != package->getInputPin_Class());
		}

		// Save 'result'
		std::shared_ptr<uml::OutputPin> result = this->getResult();
		if (result != nullptr)
		{
			saveHandler->addReference(result, "result", result->eClass() != package->getOutputPin_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getReadIsClassifiedObjectAction_Attribute_isDirect()) )
		{
			saveHandler->addAttribute("isDirect", this->getIsDirect());
		}
	// Add references
		saveHandler->addReference(this->getClassifier(), "classifier", getClassifier()->eClass() != uml::umlPackage::eInstance()->getClassifier_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> ReadIsClassifiedObjectActionImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getReadIsClassifiedObjectAction_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any ReadIsClassifiedObjectActionImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER:
			return eAny(getClassifier(),uml::umlPackage::CLASSIFIER_CLASS,false); //19427
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT:
			return eAny(getIsDirect(),ecore::ecorePackage::EBOOLEAN_CLASS,false); //19428
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT:
			return eAny(getObject(),uml::umlPackage::INPUTPIN_CLASS,false); //19429
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT:
			return eAny(getResult(),uml::umlPackage::OUTPUTPIN_CLASS,false); //19430
	}
	return ActionImpl::eGet(featureID, resolve, coreType);
}

bool ReadIsClassifiedObjectActionImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER:
			return getClassifier() != nullptr; //19427
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT:
			return getIsDirect() != false; //19428
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT:
			return getObject() != nullptr; //19429
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT:
			return getResult() != nullptr; //19430
	}
	return ActionImpl::internalEIsSet(featureID);
}

bool ReadIsClassifiedObjectActionImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_CLASSIFIER:
		{
			// CAST Any to uml::Classifier
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Classifier> _classifier = std::dynamic_pointer_cast<uml::Classifier>(_temp);
			setClassifier(_classifier); //19427
			return true;
		}
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_ISDIRECT:
		{
			// CAST Any to bool
			bool _isDirect = newValue->get<bool>();
			setIsDirect(_isDirect); //19428
			return true;
		}
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_OBJECT:
		{
			// CAST Any to uml::InputPin
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::InputPin> _object = std::dynamic_pointer_cast<uml::InputPin>(_temp);
			setObject(_object); //19429
			return true;
		}
		case uml::umlPackage::READISCLASSIFIEDOBJECTACTION_ATTRIBUTE_RESULT:
		{
			// CAST Any to uml::OutputPin
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::OutputPin> _result = std::dynamic_pointer_cast<uml::OutputPin>(_temp);
			setResult(_result); //19430
			return true;
		}
	}

	return ActionImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any ReadIsClassifiedObjectActionImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;
 
  	switch(operationID)
	{
		// uml::ReadIsClassifiedObjectAction::boolean_result(Any, std::map) : bool: 879439704
		case umlPackage::READISCLASSIFIEDOBJECTACTION_OPERATION_BOOLEAN_RESULT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->boolean_result(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ReadIsClassifiedObjectAction::multiplicity_of_input(Any, std::map) : bool: 283873246
		case umlPackage::READISCLASSIFIEDOBJECTACTION_OPERATION_MULTIPLICITY_OF_INPUT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->multiplicity_of_input(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ReadIsClassifiedObjectAction::multiplicity_of_output(Any, std::map) : bool: 1528670395
		case umlPackage::READISCLASSIFIEDOBJECTACTION_OPERATION_MULTIPLICITY_OF_OUTPUT_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->multiplicity_of_output(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::ReadIsClassifiedObjectAction::no_type(Any, std::map) : bool: 3290549392
		case umlPackage::READISCLASSIFIEDOBJECTACTION_OPERATION_NO_TYPE_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			Any incoming_param_diagnostics;
			std::list<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<Any >();
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			std::list<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>> >();
			result = eAny(this->no_type(incoming_param_diagnostics,incoming_param_context),0,false);
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

std::shared_ptr<uml::ReadIsClassifiedObjectAction> ReadIsClassifiedObjectActionImpl::getThisReadIsClassifiedObjectActionPtr() const
{
	return m_thisReadIsClassifiedObjectActionPtr.lock();
}
void ReadIsClassifiedObjectActionImpl::setThisReadIsClassifiedObjectActionPtr(std::weak_ptr<uml::ReadIsClassifiedObjectAction> thisReadIsClassifiedObjectActionPtr)
{
	m_thisReadIsClassifiedObjectActionPtr = thisReadIsClassifiedObjectActionPtr;
	setThisActionPtr(thisReadIsClassifiedObjectActionPtr);
}


