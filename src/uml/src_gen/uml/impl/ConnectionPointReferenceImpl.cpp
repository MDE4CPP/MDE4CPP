#include "uml/impl/ConnectionPointReferenceImpl.hpp"

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

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Pseudostate.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

#include "uml/Vertex.hpp"

//Factories an Package includes
#include "uml/impl/UmlFactoryImpl.hpp"
#include "uml/impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{	
}

ConnectionPointReferenceImpl::~ConnectionPointReferenceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ConnectionPointReference "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Region > par_container)
:ConnectionPointReferenceImpl()
{
	m_container = par_container;
	m_namespace = par_container;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace > par_namespace)
:ConnectionPointReferenceImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Element > par_owner)
:ConnectionPointReferenceImpl()
{
	m_owner = par_owner;
}

//Additional constructor for the containments back reference
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::State > par_state)
:ConnectionPointReferenceImpl()
{
	m_state = par_state;
	m_namespace = par_state;
}


ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(const ConnectionPointReferenceImpl & obj):ConnectionPointReferenceImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ConnectionPointReference "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_container  = obj.getContainer();

	std::shared_ptr<Bag<uml::Pseudostate>> _entry = obj.getEntry();
	m_entry.reset(new Bag<uml::Pseudostate>(*(obj.getEntry().get())));

	std::shared_ptr<Bag<uml::Pseudostate>> _exit = obj.getExit();
	m_exit.reset(new Bag<uml::Pseudostate>(*(obj.getExit().get())));

	std::shared_ptr<Bag<uml::Transition>> _incoming = obj.getIncoming();
	m_incoming.reset(new Bag<uml::Transition>(*(obj.getIncoming().get())));

	m_namespace  = obj.getNamespace();

	std::shared_ptr<Bag<uml::Transition>> _outgoing = obj.getOutgoing();
	m_outgoing.reset(new Bag<uml::Transition>(*(obj.getOutgoing().get())));

	m_owner  = obj.getOwner();

	m_state  = obj.getState();


	//Clone references with containment (deep copy)

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

std::shared_ptr<ecore::EObject>  ConnectionPointReferenceImpl::copy() const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(*this));
	element->setThisConnectionPointReferencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectionPointReferenceImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getConnectionPointReference_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ConnectionPointReferenceImpl::entry_pseudostates(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectionPointReferenceImpl::exit_pseudostates(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getEntry() const
{
	if(m_entry == nullptr)
	{
		m_entry.reset(new Bag<uml::Pseudostate>());
		
		
	}

    return m_entry;
}


std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getExit() const
{
	if(m_exit == nullptr)
	{
		m_exit.reset(new Bag<uml::Pseudostate>());
		
		
	}

    return m_exit;
}


std::weak_ptr<uml::State > ConnectionPointReferenceImpl::getState() const
{

    return m_state;
}
void ConnectionPointReferenceImpl::setState(std::shared_ptr<uml::State> _state)
{
    m_state = _state;
}

//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > ConnectionPointReferenceImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> ConnectionPointReferenceImpl::getOwnedElement() const
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

std::weak_ptr<uml::Element > ConnectionPointReferenceImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<ConnectionPointReference> ConnectionPointReferenceImpl::getThisConnectionPointReferencePtr() const
{
	return m_thisConnectionPointReferencePtr.lock();
}
void ConnectionPointReferenceImpl::setThisConnectionPointReferencePtr(std::weak_ptr<ConnectionPointReference> thisConnectionPointReferencePtr)
{
	m_thisConnectionPointReferencePtr = thisConnectionPointReferencePtr;
	setThisVertexPtr(thisConnectionPointReferencePtr);
}
std::shared_ptr<ecore::EObject> ConnectionPointReferenceImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any ConnectionPointReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = m_entry->begin();
			Bag<uml::Pseudostate>::iterator end = m_entry->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5312
		}
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Pseudostate>::iterator iter = m_exit->begin();
			Bag<uml::Pseudostate>::iterator end = m_exit->end();
			while (iter != end)
			{
				tempList->add(*iter);
				iter++;
			}
			return eAny(tempList); //5313
		}
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getState().lock())); //5314
	}
	return VertexImpl::eGet(featureID, resolve, coreType);
}
bool ConnectionPointReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
			return getEntry() != nullptr; //5312
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
			return getExit() != nullptr; //5313
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
			return getState().lock() != nullptr; //5314
	}
	return VertexImpl::internalEIsSet(featureID);
}
bool ConnectionPointReferenceImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> entryList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				entryList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterEntry = m_entry->begin();
			Bag<uml::Pseudostate>::iterator endEntry = m_entry->end();
			while (iterEntry != endEntry)
			{
				if (entryList->find(*iterEntry) == -1)
				{
					m_entry->erase(*iterEntry);
				}
				iterEntry++;
			}

			iterEntry = entryList->begin();
			endEntry = entryList->end();
			while (iterEntry != endEntry)
			{
				if (m_entry->find(*iterEntry) == -1)
				{
					m_entry->add(*iterEntry);
				}
				iterEntry++;			
			}
			return true;
		}
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Pseudostate>> exitList(new Bag<uml::Pseudostate>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				exitList->add(std::dynamic_pointer_cast<uml::Pseudostate>(*iter));
				iter++;
			}
			
			Bag<uml::Pseudostate>::iterator iterExit = m_exit->begin();
			Bag<uml::Pseudostate>::iterator endExit = m_exit->end();
			while (iterExit != endExit)
			{
				if (exitList->find(*iterExit) == -1)
				{
					m_exit->erase(*iterExit);
				}
				iterExit++;
			}

			iterExit = exitList->begin();
			endExit = exitList->end();
			while (iterExit != endExit)
			{
				if (m_exit->find(*iterExit) == -1)
				{
					m_exit->add(*iterExit);
				}
				iterExit++;			
			}
			return true;
		}
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>(_temp);
			setState(_state); //5314
			return true;
		}
	}

	return VertexImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ConnectionPointReferenceImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::map<std::string, std::string> attr_list = loadHandler->getAttributeList();
	loadAttributes(loadHandler, attr_list);

	//
	// Create new objects (from references (containment == true))
	//
	// get UmlFactory
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler);
	}
}		

void ConnectionPointReferenceImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("entry");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("entry")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
		}

		iter = attr_list.find("exit");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("exit")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void ConnectionPointReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	VertexImpl::loadNode(nodeName, loadHandler);
}

void ConnectionPointReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_ENTRY:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _entry = getEntry();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate> _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_entry->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_EXIT:
		{
			std::shared_ptr<Bag<uml::Pseudostate>> _exit = getExit();
			for(std::shared_ptr<ecore::EObject> ref : references)
			{
				std::shared_ptr<uml::Pseudostate> _r = std::dynamic_pointer_cast<uml::Pseudostate>(ref);
				if (_r != nullptr)
				{
					_exit->push_back(_r);
				}				
			}
			return;
		}

		case uml::UmlPackage::CONNECTIONPOINTREFERENCE_ATTRIBUTE_STATE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::State> _state = std::dynamic_pointer_cast<uml::State>( references.front() );
				setState(_state);
			}
			
			return;
		}
	}
	VertexImpl::resolveReferences(featureID, references);
}

void ConnectionPointReferenceImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	VertexImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ConnectionPointReferenceImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

		// Add references
		std::shared_ptr<Bag<uml::Pseudostate>> entry_list = this->getEntry();
		for (std::shared_ptr<uml::Pseudostate > object : *entry_list)
		{ 
			saveHandler->addReferences("entry", object);
		}
		std::shared_ptr<Bag<uml::Pseudostate>> exit_list = this->getExit();
		for (std::shared_ptr<uml::Pseudostate > object : *exit_list)
		{ 
			saveHandler->addReferences("exit", object);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

