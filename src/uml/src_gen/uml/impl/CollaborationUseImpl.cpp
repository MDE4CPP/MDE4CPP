#include "uml/impl/CollaborationUseImpl.hpp"

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
#include "uml/impl/UmlPackageImpl.hpp"

//Forward declaration includes
#include "persistence/interfaces/XLoadHandler.hpp" // used for Persistence
#include "persistence/interfaces/XSaveHandler.hpp" // used for Persistence
#include "uml/UmlFactory.hpp"
#include "uml/UmlPackage.hpp"

#include <exception> // used in Persistence

#include "uml/Collaboration.hpp"

#include "uml/Comment.hpp"

#include "uml/Dependency.hpp"

#include "uml/Element.hpp"

#include "uml/NamedElement.hpp"

#include "uml/Namespace.hpp"

#include "uml/StringExpression.hpp"

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
CollaborationUseImpl::CollaborationUseImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_roleBinding.reset(new Subset<uml::Dependency, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >()" << std::endl;
		#endif
	
	

	

	//Init references
		/*Subset*/
		m_roleBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

	
}

CollaborationUseImpl::~CollaborationUseImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete CollaborationUse "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:CollaborationUseImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			CollaborationUseImpl::CollaborationUseImpl(std::weak_ptr<uml::Element > par_owner)
			:CollaborationUseImpl()
			{
			    m_owner = par_owner;
			}






CollaborationUseImpl::CollaborationUseImpl(const CollaborationUseImpl & obj):CollaborationUseImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy CollaborationUse "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	m_namespace  = obj.getNamespace();

	m_owner  = obj.getOwner();

	m_type  = obj.getType();


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
	std::shared_ptr<Bag<uml::Dependency>> _roleBindingList = obj.getRoleBinding();
	for(std::shared_ptr<uml::Dependency> _roleBinding : *_roleBindingList)
	{
		this->getRoleBinding()->add(std::shared_ptr<uml::Dependency>(std::dynamic_pointer_cast<uml::Dependency>(_roleBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_roleBinding" << std::endl;
	#endif

		/*Subset*/
		m_roleBinding->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_roleBinding - Subset<uml::Dependency, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  CollaborationUseImpl::copy() const
{
	std::shared_ptr<CollaborationUseImpl> element(new CollaborationUseImpl(*this));
	element->setThisCollaborationUsePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> CollaborationUseImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getCollaborationUse_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
bool CollaborationUseImpl::client_elements(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::connectors(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool CollaborationUseImpl::every_role(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::Dependency, uml::Element>> CollaborationUseImpl::getRoleBinding() const
{

    return m_roleBinding;
}


std::shared_ptr<uml::Collaboration > CollaborationUseImpl::getType() const
{
//assert(m_type);
    return m_type;
}
void CollaborationUseImpl::setType(std::shared_ptr<uml::Collaboration> _type)
{
    m_type = _type;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> CollaborationUseImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > CollaborationUseImpl::getOwner() const
{
	return m_owner;
}


std::shared_ptr<CollaborationUse> CollaborationUseImpl::getThisCollaborationUsePtr() const
{
	return m_thisCollaborationUsePtr.lock();
}
void CollaborationUseImpl::setThisCollaborationUsePtr(std::weak_ptr<CollaborationUse> thisCollaborationUsePtr)
{
	m_thisCollaborationUsePtr = thisCollaborationUsePtr;
	setThisNamedElementPtr(thisCollaborationUsePtr);
}
std::shared_ptr<ecore::EObject> CollaborationUseImpl::eContainer() const
{
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
Any CollaborationUseImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING:
			return eAny(getRoleBinding()); //439
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
			return eAny(getType()); //4310
	}
	return NamedElementImpl::eGet(featureID, resolve, coreType);
}
bool CollaborationUseImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_ROLEBINDING:
			return getRoleBinding() != nullptr; //439
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
			return getType() != nullptr; //4310
	}
	return NamedElementImpl::internalEIsSet(featureID);
}
bool CollaborationUseImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Collaboration> _type = newValue->get<std::shared_ptr<uml::Collaboration>>();
			setType(_type); //4310
			return true;
		}
	}

	return NamedElementImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void CollaborationUseImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void CollaborationUseImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("type");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("type")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	NamedElementImpl::loadAttributes(loadHandler, attr_list);
}

void CollaborationUseImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{

	try
	{
		if ( nodeName.compare("roleBinding") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Dependency";
			}
			std::shared_ptr<uml::Dependency> roleBinding = std::dynamic_pointer_cast<uml::Dependency>(modelFactory->create(typeName));
			if (roleBinding != nullptr)
			{
				std::shared_ptr<Subset<uml::Dependency, uml::Element>> list_roleBinding = this->getRoleBinding();
				list_roleBinding->push_back(roleBinding);
				loadHandler->handleChild(roleBinding);
			}
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

	NamedElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void CollaborationUseImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::COLLABORATIONUSE_ATTRIBUTE_TYPE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Collaboration> _type = std::dynamic_pointer_cast<uml::Collaboration>( references.front() );
				setType(_type);
			}
			
			return;
		}
	}
	NamedElementImpl::resolveReferences(featureID, references);
}

void CollaborationUseImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamedElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
}

void CollaborationUseImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'roleBinding'
		for (std::shared_ptr<uml::Dependency> roleBinding : *this->getRoleBinding()) 
		{
			saveHandler->addReference(roleBinding, "roleBinding", roleBinding->eClass() != package->getDependency_Class());
		}
	

		// Add references
		saveHandler->addReference("type", this->getType());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

