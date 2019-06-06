#include "uml/impl/VertexImpl.hpp"

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

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/Region.hpp"

#include "uml/State.hpp"

#include "uml/StateMachine.hpp"

#include "uml/StringExpression.hpp"

#include "uml/Transition.hpp"

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
VertexImpl::VertexImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
	

		m_incoming.reset(new Bag<uml::Transition>());
	
	

		m_outgoing.reset(new Bag<uml::Transition>());
	
	

	//Init references
	

	
	

	
	
}

VertexImpl::~VertexImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Vertex "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Region > par_container)
			:VertexImpl()
			{
			    m_container = par_container;
				m_namespace = par_container;
			}





//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:VertexImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			VertexImpl::VertexImpl(std::weak_ptr<uml::Element > par_owner)
			:VertexImpl()
			{
			    m_owner = par_owner;
			}






VertexImpl::VertexImpl(const VertexImpl & obj):VertexImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Vertex "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
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

std::shared_ptr<ecore::EObject>  VertexImpl::copy() const
{
	std::shared_ptr<VertexImpl> element(new VertexImpl(*this));
	element->setThisVertexPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> VertexImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getVertex_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::StateMachine> VertexImpl::containingStateMachine()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Transition> > VertexImpl::getIncomings()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Transition> > VertexImpl::getOutgoings()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInRegion(std::shared_ptr<uml::Region>  r)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool VertexImpl::isContainedInState(std::shared_ptr<uml::State>  s)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::weak_ptr<uml::Region > VertexImpl::getContainer() const
{

    return m_container;
}
void VertexImpl::setContainer(std::shared_ptr<uml::Region> _container)
{
    m_container = _container;
}

std::shared_ptr<Bag<uml::Transition>> VertexImpl::getIncoming() const
{

    return m_incoming;
}


std::shared_ptr<Bag<uml::Transition>> VertexImpl::getOutgoing() const
{

    return m_outgoing;
}


//*********************************
// Union Getter
//*********************************
std::weak_ptr<uml::Namespace > VertexImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> VertexImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > VertexImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<Vertex> VertexImpl::getThisVertexPtr() const
{
	return m_thisVertexPtr.lock();
}
void VertexImpl::setThisVertexPtr(std::weak_ptr<Vertex> thisVertexPtr)
{
	m_thisVertexPtr = thisVertexPtr;
	setThisNamedElementPtr(thisVertexPtr);
}
std::shared_ptr<ecore::EObject> VertexImpl::eContainer() const
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
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any VertexImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getContainer().lock())); //2549
		case UmlPackage::VERTEX_ATTRIBUTE_INCOMING:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Transition>::iterator iter = m_incoming->begin();
			Bag<uml::Transition>::iterator end = m_incoming->end();
			while (iter != end)
			{
				tempList->add(*iter);
			}
			return eAny(tempList); //25410
		}
		case UmlPackage::VERTEX_ATTRIBUTE_OUTGOING:
		{
			std::shared_ptr<Bag<ecore::EObject>> tempList(new Bag<ecore::EObject>());
			Bag<uml::Transition>::iterator iter = m_outgoing->begin();
			Bag<uml::Transition>::iterator end = m_outgoing->end();
			while (iter != end)
			{
				tempList->add(*iter);
			}
			return eAny(tempList); //25411
		}
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool VertexImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
			return getContainer().lock() != nullptr; //2549
		case UmlPackage::VERTEX_ATTRIBUTE_INCOMING:
			return getIncoming() != nullptr; //25410
		case UmlPackage::VERTEX_ATTRIBUTE_OUTGOING:
			return getOutgoing() != nullptr; //25411
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool VertexImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>(_temp);
			setContainer(_container); //2549
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void VertexImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void VertexImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void VertexImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void VertexImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::VERTEX_ATTRIBUTE_CONTAINER:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Region> _container = std::dynamic_pointer_cast<uml::Region>( references.front() );
				setContainer(_container);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void VertexImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void VertexImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

