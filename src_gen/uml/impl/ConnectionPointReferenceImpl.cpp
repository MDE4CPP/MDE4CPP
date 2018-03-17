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

#include "abstractDataTypes/Bag.hpp"
#include "abstractDataTypes/Subset.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "abstractDataTypes/Union.hpp"
#include "abstractDataTypes/SubsetUnion.hpp"
#include "boost/any.hpp"
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

#include "uml/Pseudostate.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

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
ConnectionPointReferenceImpl::ConnectionPointReferenceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		m_entry.reset(new Bag<uml::Pseudostate>());
	
	

		m_exit.reset(new Bag<uml::Pseudostate>());
	
	

	

	//Init references
	
	

	
	

	
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
			}





//Additional constructor for the containments back reference
			ConnectionPointReferenceImpl::ConnectionPointReferenceImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:ConnectionPointReferenceImpl()
			{
			    m_namespace = par_namespace;
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

std::shared_ptr<ecore::EObject>  ConnectionPointReferenceImpl::copy() const
{
	std::shared_ptr<ConnectionPointReferenceImpl> element(new ConnectionPointReferenceImpl(*this));
	element->setThisConnectionPointReferencePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ConnectionPointReferenceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getConnectionPointReference_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool ConnectionPointReferenceImpl::entry_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ConnectionPointReferenceImpl::exit_pseudostates(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getEntry() const
{

    return m_entry;
}


std::shared_ptr<Bag<uml::Pseudostate>> ConnectionPointReferenceImpl::getExit() const
{

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
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ConnectionPointReferenceImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<ConnectionPointReference> ConnectionPointReferenceImpl::getThisConnectionPointReferencePtr()
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
boost::any ConnectionPointReferenceImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_ENTRY:
			return getEntry(); //6413
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_EXIT:
			return getExit(); //6414
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_STATE:
			return getState(); //6415
	}
	return VertexImpl::internalEIsSet(featureID);
}
bool ConnectionPointReferenceImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_ENTRY:
			return getEntry() != nullptr; //6413
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_EXIT:
			return getExit() != nullptr; //6414
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_STATE:
			return getState().lock() != nullptr; //6415
	}
	return VertexImpl::internalEIsSet(featureID);
}
bool ConnectionPointReferenceImpl::eSet(int featureID, boost::any newValue)
{
	switch(featureID)
	{
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_STATE:
		{
			// BOOST CAST
			std::shared_ptr<uml::State> _state = boost::any_cast<std::shared_ptr<uml::State>>(newValue);
			setState(_state); //6415
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
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void ConnectionPointReferenceImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	VertexImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ConnectionPointReferenceImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_ENTRY:
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

		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_EXIT:
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

		case UmlPackage::CONNECTIONPOINTREFERENCE_EREFERENCE_STATE:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
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

