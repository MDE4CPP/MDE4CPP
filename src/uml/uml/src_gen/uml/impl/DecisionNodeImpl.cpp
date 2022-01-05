
#include "uml/impl/DecisionNodeImpl.hpp"

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


#include "abstractDataTypes/Any.hpp"
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
#include "uml/Activity.hpp"
#include "uml/ActivityEdge.hpp"
#include "uml/ActivityGroup.hpp"
#include "uml/ActivityNode.hpp"
#include "uml/ActivityPartition.hpp"
#include "uml/Behavior.hpp"
#include "uml/Classifier.hpp"
#include "uml/Comment.hpp"
#include "uml/ControlNode.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/InterruptibleActivityRegion.hpp"
#include "uml/Namespace.hpp"
#include "uml/ObjectFlow.hpp"
#include "uml/RedefinableElement.hpp"
#include "uml/StringExpression.hpp"
#include "uml/StructuredActivityNode.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DecisionNodeImpl::DecisionNodeImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

DecisionNodeImpl::~DecisionNodeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DecisionNode "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::Activity> par_activity)
:DecisionNodeImpl()
{
	m_activity = par_activity;
	m_owner = par_activity;
}

//Additional constructor for the containments back reference
DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::StructuredActivityNode> par_inStructuredNode)
:DecisionNodeImpl()
{
	m_inStructuredNode = par_inStructuredNode;
	m_owner = par_inStructuredNode;
}

//Additional constructor for the containments back reference
DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::Namespace> par_namespace)
:DecisionNodeImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
DecisionNodeImpl::DecisionNodeImpl(std::weak_ptr<uml::Element> par_owner)
:DecisionNodeImpl()
{
	m_owner = par_owner;
}

DecisionNodeImpl::DecisionNodeImpl(const DecisionNodeImpl & obj): DecisionNodeImpl()
{
	*this = obj;
}

DecisionNodeImpl& DecisionNodeImpl::operator=(const DecisionNodeImpl & obj)
{
	//call overloaded =Operator for each base class
	ControlNodeImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of DecisionNode 
	 * which is generated by the compiler (as DecisionNode is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//DecisionNode::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy DecisionNode "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)

	//copy references with no containment (soft copy)
	m_decisionInput  = obj.getDecisionInput();
	m_decisionInputFlow  = obj.getDecisionInputFlow();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> DecisionNodeImpl::copy() const
{
	std::shared_ptr<DecisionNodeImpl> element(new DecisionNodeImpl());
	*element =(*this);
	element->setThisDecisionNodePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool DecisionNodeImpl::decision_input_flow_incoming(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::incoming_control_one_input_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::incoming_object_one_input_parameter(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::incoming_outgoing_edges(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::two_input_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool DecisionNodeImpl::zero_input_parameters(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference decisionInput */
std::shared_ptr<uml::Behavior> DecisionNodeImpl::getDecisionInput() const
{
    return m_decisionInput;
}
void DecisionNodeImpl::setDecisionInput(std::shared_ptr<uml::Behavior> _decisionInput)
{
    m_decisionInput = _decisionInput;
	
}

/* Getter & Setter for reference decisionInputFlow */
std::shared_ptr<uml::ObjectFlow> DecisionNodeImpl::getDecisionInputFlow() const
{
    return m_decisionInputFlow;
}
void DecisionNodeImpl::setDecisionInputFlow(std::shared_ptr<uml::ObjectFlow> _decisionInputFlow)
{
    m_decisionInputFlow = _decisionInputFlow;
	
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::ActivityGroup>> DecisionNodeImpl::getInGroup() const
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

std::shared_ptr<Union<uml::Element>> DecisionNodeImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> DecisionNodeImpl::getOwner() const
{
	return m_owner;
}

std::shared_ptr<Union<uml::RedefinableElement>> DecisionNodeImpl::getRedefinedElement() const
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
std::shared_ptr<ecore::EObject> DecisionNodeImpl::eContainer() const
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
void DecisionNodeImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void DecisionNodeImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("decisionInput");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decisionInput")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("decisionInputFlow");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("decisionInputFlow")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	ControlNodeImpl::loadAttributes(loadHandler, attr_list);
}

void DecisionNodeImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	ControlNodeImpl::loadNode(nodeName, loadHandler);
}

void DecisionNodeImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Behavior> _decisionInput = std::dynamic_pointer_cast<uml::Behavior>( references.front() );
				setDecisionInput(_decisionInput);
			}
			
			return;
		}

		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::ObjectFlow> _decisionInputFlow = std::dynamic_pointer_cast<uml::ObjectFlow>( references.front() );
				setDecisionInputFlow(_decisionInputFlow);
			}
			
			return;
		}
	}
	ControlNodeImpl::resolveReferences(featureID, references);
}

void DecisionNodeImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	ControlNodeImpl::saveContent(saveHandler);
	
	ActivityNodeImpl::saveContent(saveHandler);
	
	RedefinableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void DecisionNodeImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
	// Add references
		saveHandler->addReference(this->getDecisionInput(), "decisionInput", getDecisionInput()->eClass() != uml::umlPackage::eInstance()->getBehavior_Class()); 
		saveHandler->addReference(this->getDecisionInputFlow(), "decisionInputFlow", getDecisionInputFlow()->eClass() != uml::umlPackage::eInstance()->getObjectFlow_Class()); 
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> DecisionNodeImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getDecisionNode_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
Any DecisionNodeImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUT:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDecisionInput();
			return eAny(returnValue,uml::umlPackage::BEHAVIOR_CLASS,false); //6620
		}
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW:
		{
			std::shared_ptr<ecore::EObject> returnValue=getDecisionInputFlow();
			return eAny(returnValue,uml::umlPackage::OBJECTFLOW_CLASS,false); //6621
		}
	}
	return ControlNodeImpl::eGet(featureID, resolve, coreType);
}

bool DecisionNodeImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUT:
			return getDecisionInput() != nullptr; //6620
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW:
			return getDecisionInputFlow() != nullptr; //6621
	}
	return ControlNodeImpl::internalEIsSet(featureID);
}

bool DecisionNodeImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUT:
		{
			// CAST Any to uml::Behavior
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Behavior> _decisionInput = std::dynamic_pointer_cast<uml::Behavior>(_temp);
			setDecisionInput(_decisionInput); //6620
			return true;
		}
		case uml::umlPackage::DECISIONNODE_ATTRIBUTE_DECISIONINPUTFLOW:
		{
			// CAST Any to uml::ObjectFlow
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::ObjectFlow> _decisionInputFlow = std::dynamic_pointer_cast<uml::ObjectFlow>(_temp);
			setDecisionInputFlow(_decisionInputFlow); //6621
			return true;
		}
	}

	return ControlNodeImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
Any DecisionNodeImpl::eInvoke(int operationID, std::shared_ptr<std::list<Any>> arguments)
{
	Any result;

  	switch(operationID)
	{
		// uml::DecisionNode::decision_input_flow_incoming(Any, std::map) : bool: 1478029581
		case umlPackage::DECISIONNODE_OPERATION_DECISION_INPUT_FLOW_INCOMING_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->decision_input_flow_incoming(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::edges(Any, std::map) : bool: 922337066
		case umlPackage::DECISIONNODE_OPERATION_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->edges(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::incoming_control_one_input_parameter(Any, std::map) : bool: 369422792
		case umlPackage::DECISIONNODE_OPERATION_INCOMING_CONTROL_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->incoming_control_one_input_parameter(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::incoming_object_one_input_parameter(Any, std::map) : bool: 2140105925
		case umlPackage::DECISIONNODE_OPERATION_INCOMING_OBJECT_ONE_INPUT_PARAMETER_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->incoming_object_one_input_parameter(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::incoming_outgoing_edges(Any, std::map) : bool: 397009690
		case umlPackage::DECISIONNODE_OPERATION_INCOMING_OUTGOING_EDGES_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->incoming_outgoing_edges(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::parameters(Any, std::map) : bool: 1666719950
		case umlPackage::DECISIONNODE_OPERATION_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->parameters(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::two_input_parameters(Any, std::map) : bool: 1310848977
		case umlPackage::DECISIONNODE_OPERATION_TWO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->two_input_parameters(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}
		// uml::DecisionNode::zero_input_parameters(Any, std::map) : bool: 707758549
		case umlPackage::DECISIONNODE_OPERATION_ZERO_INPUT_PARAMETERS_EDIAGNOSTICCHAIN_EMAP:
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
			result = eAny(this->zero_input_parameters(incoming_param_diagnostics,incoming_param_context),0,false);
			break;
		}

		default:
		{
			// call superTypes
			result = ControlNodeImpl::eInvoke(operationID, arguments);
			if (!result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::DecisionNode> DecisionNodeImpl::getThisDecisionNodePtr() const
{
	return m_thisDecisionNodePtr.lock();
}
void DecisionNodeImpl::setThisDecisionNodePtr(std::weak_ptr<uml::DecisionNode> thisDecisionNodePtr)
{
	m_thisDecisionNodePtr = thisDecisionNodePtr;
	setThisControlNodePtr(thisDecisionNodePtr);
}

