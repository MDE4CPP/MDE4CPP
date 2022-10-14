
#include "uml/impl/PseudostateImpl.hpp"
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
#include <stdexcept>
#include "abstractDataTypes/SubsetUnion.hpp"


#include "ecore/EcoreAny.hpp"
#include "ecore/EcoreContainerAny.hpp"
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
#include "uml/Comment.hpp"
#include "uml/Dependency.hpp"
#include "uml/Element.hpp"
#include "uml/Namespace.hpp"
#include "uml/Region.hpp"
#include "uml/State.hpp"
#include "uml/StateMachine.hpp"
#include "uml/StringExpression.hpp"
#include "uml/Transition.hpp"
#include "uml/Vertex.hpp"
//Factories and Package includes
#include "uml/umlPackage.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PseudostateImpl::PseudostateImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PseudostateImpl::~PseudostateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Pseudostate "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Region> par_container)
:PseudostateImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PseudostateImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Element> par_owner)
:PseudostateImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::State> par_state)
:PseudostateImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}

//Additional constructor for the containments back reference
PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::StateMachine> par_stateMachine)
:PseudostateImpl()
{
	m_stateMachine = par_stateMachine;
	m_namespace = par_stateMachine;
}

PseudostateImpl::PseudostateImpl(const PseudostateImpl & obj): PseudostateImpl()
{
	*this = obj;
}

PseudostateImpl& PseudostateImpl::operator=(const PseudostateImpl & obj)
{
	//call overloaded =Operator for each base class
	VertexImpl::operator=(obj);
	/* TODO: Find out if this call is necessary
	 * Currently, this causes an error because it calls an implicit assignment operator of Pseudostate 
	 * which is generated by the compiler (as Pseudostate is an abstract class and does not have a user-defined assignment operator).
	 * Implicit compiler-generated assignment operators however only create shallow copies of members,
	 * which implies, that not a real deep copy is created when using the copy()-method.
	 * 
	 * NOTE: Since all members are deep-copied by this assignment-operator anyway, why is it even necessary to call this implicit assignment-operator?
	 * This is only done for ecore-models, not for UML-models.
	 */
	//Pseudostate::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Pseudostate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_kind = obj.getKind();

	//copy references with no containment (soft copy)
	m_state  = obj.getState();
	m_stateMachine  = obj.getStateMachine();
	//Clone references with containment (deep copy)
	return *this;
}

std::shared_ptr<ecore::EObject> PseudostateImpl::copy() const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl());
	*element =(*this);
	element->setThisPseudostatePtr(element);
	return element;
}

//*********************************
// Operations
//*********************************
bool PseudostateImpl::choice_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::fork_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::history_vertices(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::initial_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::join_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::junction_vertex(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::outgoing_from_initial(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::transitions_incoming(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

bool PseudostateImpl::transitions_outgoing(std::shared_ptr<Any> diagnostics, std::shared_ptr<std::map < Any, Any>> context)
{
	throw std::runtime_error("UnsupportedOperationException: " + std::string(__PRETTY_FUNCTION__));
}

//*********************************
// Attribute Getters & Setters
//*********************************
/* Getter & Setter for attribute kind */
uml::PseudostateKind PseudostateImpl::getKind() const 
{
	return m_kind;
}
void PseudostateImpl::setKind(uml::PseudostateKind _kind)
{
	m_kind = _kind;
	
}

//*********************************
// Reference Getters & Setters
//*********************************
/* Getter & Setter for reference state */
std::weak_ptr<uml::State> PseudostateImpl::getState() const
{
    return m_state;
}
void PseudostateImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
	
}

/* Getter & Setter for reference stateMachine */
std::weak_ptr<uml::StateMachine> PseudostateImpl::getStateMachine() const
{
    return m_stateMachine;
}
void PseudostateImpl::setStateMachine(std::weak_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
	
}

//*********************************
// Union Getter
//*********************************

//*********************************
// Container Getter
//*********************************
std::shared_ptr<ecore::EObject> PseudostateImpl::eContainer() const
{
	if(auto wp = m_container.lock())
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

	if(auto wp = m_state.lock())
	{
		return wp;
	}

	if(auto wp = m_stateMachine.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Persistence Functions
//*********************************
void PseudostateImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PseudostateImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("kind");
		if ( iter != attr_list.end() )
		{
			uml::PseudostateKind value = uml::PseudostateKind::INITIAL;
			std::string literal = iter->second;
						if (literal == "initial")
			{
				value = uml::PseudostateKind::INITIAL;
			}
			else 			if (literal == "deepHistory")
			{
				value = uml::PseudostateKind::DEEPHISTORY;
			}
			else 			if (literal == "shallowHistory")
			{
				value = uml::PseudostateKind::SHALLOWHISTORY;
			}
			else 			if (literal == "join")
			{
				value = uml::PseudostateKind::JOIN;
			}
			else 			if (literal == "fork")
			{
				value = uml::PseudostateKind::FORK;
			}
			else 			if (literal == "junction")
			{
				value = uml::PseudostateKind::JUNCTION;
			}
			else 			if (literal == "choice")
			{
				value = uml::PseudostateKind::CHOICE;
			}
			else 			if (literal == "entryPoint")
			{
				value = uml::PseudostateKind::ENTRYPOINT;
			}
			else 			if (literal == "exitPoint")
			{
				value = uml::PseudostateKind::EXITPOINT;
			}
			else 			if (literal == "terminate")
			{
				value = uml::PseudostateKind::TERMINATE;
			}
			this->setKind(value);
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

	VertexImpl::loadAttributes(loadHandler, attr_list);
}

void PseudostateImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	//load BasePackage Nodes
	VertexImpl::loadNode(nodeName, loadHandler);
}

void PseudostateImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}

		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>( references.front() );
				setStateMachine(_stateMachine);
			}
			
			return;
		}
	}
	VertexImpl::resolveReferences(featureID, references);
}

void PseudostateImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	VertexImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
}

void PseudostateImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Add attributes
		if ( this->eIsSet(package->getPseudostate_Attribute_kind()) )
		{
			uml::PseudostateKind value = this->getKind();
			std::string literal = "";
			if (value == uml::PseudostateKind::INITIAL)
			{
				literal = "initial";
			}
			else if (value == uml::PseudostateKind::DEEPHISTORY)
			{
				literal = "deepHistory";
			}
			else if (value == uml::PseudostateKind::SHALLOWHISTORY)
			{
				literal = "shallowHistory";
			}
			else if (value == uml::PseudostateKind::JOIN)
			{
				literal = "join";
			}
			else if (value == uml::PseudostateKind::FORK)
			{
				literal = "fork";
			}
			else if (value == uml::PseudostateKind::JUNCTION)
			{
				literal = "junction";
			}
			else if (value == uml::PseudostateKind::CHOICE)
			{
				literal = "choice";
			}
			else if (value == uml::PseudostateKind::ENTRYPOINT)
			{
				literal = "entryPoint";
			}
			else if (value == uml::PseudostateKind::EXITPOINT)
			{
				literal = "exitPoint";
			}
			else if (value == uml::PseudostateKind::TERMINATE)
			{
				literal = "terminate";
			}
			saveHandler->addAttribute("kind", literal);
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

std::shared_ptr<ecore::EClass> PseudostateImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPseudostate_Class();
}

//*********************************
// EStructuralFeature Get/Set/IsSet
//*********************************
std::shared_ptr<Any> PseudostateImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
			return eAny(getKind(),uml::umlPackage::PSEUDOSTATEKIND_CLASS,false); //18913
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getState().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STATE_CLASS); //18912
		}
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
		{
			std::shared_ptr<ecore::EObject> returnValue=getStateMachine().lock();
			return eEcoreAny(returnValue,uml::umlPackage::STATEMACHINE_CLASS); //18914
		}
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}

bool PseudostateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
			return m_kind != uml::PseudostateKind::INITIAL;; //18913
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //18912
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
			return getStateMachine().lock() != nullptr; //18914
	}
	return VertexImpl::internalEIsSet(featureID);
}

bool PseudostateImpl::eSet(int featureID, std::shared_ptr<Any> newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
		{
			try
			{
				uml::PseudostateKind _kind = newValue->get<uml::PseudostateKind>();
				setKind(_kind); //18913
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for feature 'kind'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(eObject);
					if(_state)
					{
						setState(_state); //18912
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'state'. Failed to set feature!")
				return false;
			}
		return true;
		}
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
		{
			std::shared_ptr<ecore::EcoreAny> ecoreAny = std::dynamic_pointer_cast<ecore::EcoreAny>(newValue);
			if(ecoreAny)
			{
				try
				{
					std::shared_ptr<ecore::EObject> eObject = ecoreAny->getAsEObject();
					std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(eObject);
					if(_stateMachine)
					{
						setStateMachine(_stateMachine); //18914
					}
					else
					{
						throw "Invalid argument";
					}
				}
				catch(...)
				{
					DEBUG_ERROR("Invalid type stored in 'ecore::ecoreAny' for feature 'stateMachine'. Failed to set feature!")
					return false;
				}
			}
			else
			{
				DEBUG_ERROR("Invalid instance of 'ecore::ecoreAny' for feature 'stateMachine'. Failed to set feature!")
				return false;
			}
		return true;
		}
	}

	return VertexImpl::eSet(featureID, newValue);
}

//*********************************
// EOperation Invoke
//*********************************
std::shared_ptr<Any> PseudostateImpl::eInvoke(int operationID, std::shared_ptr<Bag<Any>> arguments)
{
	std::shared_ptr<Any> result;
 
  	switch(operationID)
	{
		// uml::Pseudostate::choice_vertex(Any, std::map) : bool: 268196655
		case umlPackage::PSEUDOSTATE_OPERATION_CHOICE_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'choice_vertex'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'choice_vertex'!")
				return nullptr;
			}
		
			result = eAny(this->choice_vertex(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::fork_vertex(Any, std::map) : bool: 70703214
		case umlPackage::PSEUDOSTATE_OPERATION_FORK_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'fork_vertex'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'fork_vertex'!")
				return nullptr;
			}
		
			result = eAny(this->fork_vertex(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::history_vertices(Any, std::map) : bool: 1473780509
		case umlPackage::PSEUDOSTATE_OPERATION_HISTORY_VERTICES_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'history_vertices'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'history_vertices'!")
				return nullptr;
			}
		
			result = eAny(this->history_vertices(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::initial_vertex(Any, std::map) : bool: 1119478342
		case umlPackage::PSEUDOSTATE_OPERATION_INITIAL_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'initial_vertex'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'initial_vertex'!")
				return nullptr;
			}
		
			result = eAny(this->initial_vertex(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::join_vertex(Any, std::map) : bool: 3336750216
		case umlPackage::PSEUDOSTATE_OPERATION_JOIN_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'join_vertex'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'join_vertex'!")
				return nullptr;
			}
		
			result = eAny(this->join_vertex(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::junction_vertex(Any, std::map) : bool: 1046174546
		case umlPackage::PSEUDOSTATE_OPERATION_JUNCTION_VERTEX_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'junction_vertex'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'junction_vertex'!")
				return nullptr;
			}
		
			result = eAny(this->junction_vertex(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::outgoing_from_initial(Any, std::map) : bool: 56020895
		case umlPackage::PSEUDOSTATE_OPERATION_OUTGOING_FROM_INITIAL_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'outgoing_from_initial'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'outgoing_from_initial'!")
				return nullptr;
			}
		
			result = eAny(this->outgoing_from_initial(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::transitions_incoming(Any, std::map) : bool: 1040583452
		case umlPackage::PSEUDOSTATE_OPERATION_TRANSITIONS_INCOMING_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'transitions_incoming'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'transitions_incoming'!")
				return nullptr;
			}
		
			result = eAny(this->transitions_incoming(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}
		// uml::Pseudostate::transitions_outgoing(Any, std::map) : bool: 1228342264
		case umlPackage::PSEUDOSTATE_OPERATION_TRANSITIONS_OUTGOING_EDIAGNOSTICCHAIN_EMAP:
		{
			//Retrieve input parameter 'diagnostics'
			//parameter 0
			std::shared_ptr<Any> incoming_param_diagnostics;
			Bag<Any>::const_iterator incoming_param_diagnostics_arguments_citer = std::next(arguments->begin(), 0);
			try
			{
				incoming_param_diagnostics = (*incoming_param_diagnostics_arguments_citer)->get<std::shared_ptr<Any>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'diagnostics'. Failed to invoke operation 'transitions_outgoing'!")
				return nullptr;
			}
		
			//Retrieve input parameter 'context'
			//parameter 1
			std::shared_ptr<std::map < Any, Any>> incoming_param_context;
			Bag<Any>::const_iterator incoming_param_context_arguments_citer = std::next(arguments->begin(), 1);
			try
			{
				incoming_param_context = (*incoming_param_context_arguments_citer)->get<std::shared_ptr<std::map < Any, Any>>>();
			}
			catch(...)
			{
				DEBUG_ERROR("Invalid type stored in 'Any' for parameter 'context'. Failed to invoke operation 'transitions_outgoing'!")
				return nullptr;
			}
		
			result = eAny(this->transitions_outgoing(incoming_param_diagnostics,incoming_param_context), 0, false);
			break;
		}

		default:
		{
			// call superTypes
			result = VertexImpl::eInvoke(operationID, arguments);
			if (result && !result->isEmpty())
				break;
			break;
		}
  	}

	return result;
}

std::shared_ptr<uml::Pseudostate> PseudostateImpl::getThisPseudostatePtr() const
{
	return m_thisPseudostatePtr.lock();
}
void PseudostateImpl::setThisPseudostatePtr(std::weak_ptr<uml::Pseudostate> thisPseudostatePtr)
{
	m_thisPseudostatePtr = thisPseudostatePtr;
	setThisVertexPtr(thisPseudostatePtr);
}


