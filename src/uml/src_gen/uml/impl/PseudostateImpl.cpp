#include "uml/impl/PseudostateImpl.hpp"

#ifdef DEBUG_ON
	#define DEBUG_MESSAGE(a) a
#else
	#define DEBUG_MESSAGE(a) /**/
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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"
#include <exception> // used in Persistence

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

#include "uml/Vertex.hpp"

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
PseudostateImpl::PseudostateImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
	

	

	//Init references
	

	
}

PseudostateImpl::~PseudostateImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Pseudostate "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Region > par_container)
			:PseudostateImpl()
			{
			    m_container = par_container;
				m_namespace = par_container;
			}





//Additional constructor for the containments back reference
			PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PseudostateImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::Element > par_owner)
			:PseudostateImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference
			PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::State > par_state)
			:PseudostateImpl()
			{
			    m_state = par_state;
				m_namespace = par_state;
			}





//Additional constructor for the containments back reference
			PseudostateImpl::PseudostateImpl(std::weak_ptr<uml::StateMachine > par_stateMachine)
			:PseudostateImpl()
			{
			    m_stateMachine = par_stateMachine;
				m_namespace = par_stateMachine;
			}






PseudostateImpl::PseudostateImpl(const PseudostateImpl & obj):PseudostateImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Pseudostate "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_kind = obj.getKind();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr<Bag<uml::Transition>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::Transition>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::Transition>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::Transition>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	m_state  = obj.getState();

	m_stateMachine  = obj.getStateMachine();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
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

std::shared_ptr<ecore::EObject>  PseudostateImpl::copy() const
{
	std::shared_ptr<PseudostateImpl> element(new PseudostateImpl(*this));
	element->setThisPseudostatePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PseudostateImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPseudostate_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PseudostateImpl::setKind(PseudostateKind _kind)
{
	m_kind = _kind;
} 

PseudostateKind PseudostateImpl::getKind() const 
{
	return m_kind;
}

//*********************************
// Operations
//*********************************
bool PseudostateImpl::choice_vertex(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::fork_vertex(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::history_vertices(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::initial_vertex(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::join_vertex(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::junction_vertex(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::outgoing_from_initial(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_incoming(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PseudostateImpl::transitions_outgoing(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::State > PseudostateImpl::getState() const
{

    return m_state;
}
void PseudostateImpl::setState(std::shared_ptr<uml::State> _state)
{
    m_state = _state;
}

std::weak_ptr<uml::StateMachine > PseudostateImpl::getStateMachine() const
{

    return m_stateMachine;
}
void PseudostateImpl::setStateMachine(std::shared_ptr<uml::StateMachine> _stateMachine)
{
    m_stateMachine = _stateMachine;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > PseudostateImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> PseudostateImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PseudostateImpl::getOwner() const
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
		case UmlPackage::PSEUDOSTATE_EATTRIBUTE_KIND:
			return eAny(getKind()); //6014
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATE:
			return eAny(getState()); //6013
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATEMACHINE:
			return eAny(getStateMachine()); //6015
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}
bool PseudostateImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::PSEUDOSTATE_EATTRIBUTE_KIND:
			return m_kind != PseudostateKind::INITIAL;; //6014
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATE:
			return getState().lock() != nullptr; //6013
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATEMACHINE:
			return getStateMachine().lock() != nullptr; //6015
	}
	return VertexImpl::internalEIsSet(featureID);
}
bool PseudostateImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::PSEUDOSTATE_EATTRIBUTE_KIND:
		{
			// BOOST CAST
			PseudostateKind _kind = newValue->get<PseudostateKind>();
			setKind(_kind); //6014
			return true;
		}
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<uml::State> _state = newValue->get<std::shared_ptr<uml::State>>();
			setState(_state); //6013
			return true;
		}
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATEMACHINE:
		{
			// BOOST CAST
			std::shared_ptr<uml::StateMachine> _stateMachine = newValue->get<std::shared_ptr<uml::StateMachine>>();
			setStateMachine(_stateMachine); //6015
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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
			PseudostateKind value = PseudostateKind::INITIAL;
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

void PseudostateImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	VertexImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PseudostateImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}

		case UmlPackage::PSEUDOSTATE_EREFERENCE_STATEMACHINE:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void PseudostateImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getPseudostate_EAttribute_kind()) )
		{
			PseudostateKind value = this->getKind();
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

