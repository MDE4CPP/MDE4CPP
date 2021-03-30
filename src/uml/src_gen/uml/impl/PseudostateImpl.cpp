#include "uml/impl/PseudostateImpl.hpp"

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

//Factories an Package includes
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

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
	Pseudostate::operator=(obj);

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

std::shared_ptr<ecore::EClass> PseudostateImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPseudostate_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute kind
*/
uml::PseudostateKind PseudostateImpl::getKind() const 
{
	return m_kind;
}
void PseudostateImpl::setKind(uml::PseudostateKind _kind)
{
	m_kind = _kind;
} 


//*********************************
// Operations
//*********************************
bool PseudostateImpl::choice_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::fork_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::history_vertices(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::initial_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::join_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::junction_vertex(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::outgoing_from_initial(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_incoming(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_outgoing(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference state
*/
std::weak_ptr<uml::State> PseudostateImpl::getState() const
{

    return m_state;
}
void PseudostateImpl::setState(std::weak_ptr<uml::State> _state)
{
    m_state = _state;
}


/*
Getter & Setter for reference stateMachine
*/
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
std::weak_ptr<uml::Namespace> PseudostateImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PseudostateImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element> PseudostateImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Pseudostate> PseudostateImpl::getThisPseudostatePtr() const
{
	return m_thisPseudostatePtr.lock();
}
void PseudostateImpl::setThisPseudostatePtr(std::weak_ptr<Pseudostate> thisPseudostatePtr)
{
	m_thisPseudostatePtr = thisPseudostatePtr;
	setThisVertexPtr(thisPseudostatePtr);
}
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
// Structural Feature Getter/Setter
//*********************************
Any PseudostateImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
			return eAny(getKind()); //18913
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
			return eAny(getState().lock()); //18912
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
			return eAny(getStateMachine().lock()); //18914
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}
bool PseudostateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
			return m_kind != PseudostateKind::INITIAL;; //18913
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //18912
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
			return getStateMachine().lock() != nullptr; //18914
	}
	return VertexImpl::internalEIsSet(featureID);
}
bool PseudostateImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_KIND:
		{
			// BOOST CAST
			uml::PseudostateKind _kind = newValue->get<uml::PseudostateKind>();
			setKind(_kind); //18913
			return true;
		}
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(_temp);
			setState(_state); //18912
			return true;
		}
		case uml::umlPackage::PSEUDOSTATE_ATTRIBUTE_STATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::StateMachine> _stateMachine = std::dynamic_pointer_cast<uml::StateMachine>(_temp);
			setStateMachine(_stateMachine); //18914
			return true;
		}
	}

	return VertexImpl::eSet(featureID, newValue);
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
			uml::PseudostateKind value = PseudostateKind::INITIAL;
			std::string literal = iter->second;
			if (literal == "initial")
			{
				value = PseudostateKind::INITIAL;
			}
			else if (literal == "deepHistory")
			{
				value = PseudostateKind::DEEPHISTORY;
			}
			else if (literal == "shallowHistory")
			{
				value = PseudostateKind::SHALLOWHISTORY;
			}
			else if (literal == "join")
			{
				value = PseudostateKind::JOIN;
			}
			else if (literal == "fork")
			{
				value = PseudostateKind::FORK;
			}
			else if (literal == "junction")
			{
				value = PseudostateKind::JUNCTION;
			}
			else if (literal == "choice")
			{
				value = PseudostateKind::CHOICE;
			}
			else if (literal == "entryPoint")
			{
				value = PseudostateKind::ENTRYPOINT;
			}
			else if (literal == "exitPoint")
			{
				value = PseudostateKind::EXITPOINT;
			}
			else if (literal == "terminate")
			{
				value = PseudostateKind::TERMINATE;
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
			if (value == PseudostateKind::INITIAL)
			{
				literal = "initial";
			}
			else if (value == PseudostateKind::DEEPHISTORY)
			{
				literal = "deepHistory";
			}
			else if (value == PseudostateKind::SHALLOWHISTORY)
			{
				literal = "shallowHistory";
			}
			else if (value == PseudostateKind::JOIN)
			{
				literal = "join";
			}
			else if (value == PseudostateKind::FORK)
			{
				literal = "fork";
			}
			else if (value == PseudostateKind::JUNCTION)
			{
				literal = "junction";
			}
			else if (value == PseudostateKind::CHOICE)
			{
				literal = "choice";
			}
			else if (value == PseudostateKind::ENTRYPOINT)
			{
				literal = "entryPoint";
			}
			else if (value == PseudostateKind::EXITPOINT)
			{
				literal = "exitPoint";
			}
			else if (value == PseudostateKind::TERMINATE)
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

