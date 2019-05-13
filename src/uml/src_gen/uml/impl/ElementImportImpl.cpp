#include "uml/impl/ElementImportImpl.hpp"

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

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/PackageableElement.hpp"

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
ElementImportImpl::ElementImportImpl()
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

ElementImportImpl::~ElementImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete ElementImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
			:ElementImportImpl()
			{
			    m_importingNamespace = par_importingNamespace;
				m_owner = par_importingNamespace;
			}





//Additional constructor for the containments back reference
			ElementImportImpl::ElementImportImpl(std::weak_ptr<uml::Element > par_owner)
			:ElementImportImpl()
			{
			    m_owner = par_owner;
			}






ElementImportImpl::ElementImportImpl(const ElementImportImpl & obj):ElementImportImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy ElementImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_alias = obj.getAlias();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_importingNamespace  = obj.getImportingNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getImportedElement()!=nullptr)
	{
		m_importedElement = std::dynamic_pointer_cast<uml::PackageableElement>(obj.getImportedElement()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedElement" << std::endl;
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

std::shared_ptr<ecore::EObject>  ElementImportImpl::copy() const
{
	std::shared_ptr<ElementImportImpl> element(new ElementImportImpl(*this));
	element->setThisElementImportPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> ElementImportImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getElementImport_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void ElementImportImpl::setAlias(std::string _alias)
{
	m_alias = _alias;
} 

std::string ElementImportImpl::getAlias() const 
{
	return m_alias;
}

void ElementImportImpl::setVisibility(VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

VisibilityKind ElementImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
std::string ElementImportImpl::getName()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::imported_element_is_public(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ElementImportImpl::visibility_public_or_private(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::PackageableElement > ElementImportImpl::getImportedElement() const
{
//assert(m_importedElement);
    return m_importedElement;
}
void ElementImportImpl::setImportedElement(std::shared_ptr<uml::PackageableElement> _importedElement)
{
    m_importedElement = _importedElement;
}

std::weak_ptr<uml::Namespace > ElementImportImpl::getImportingNamespace() const
{
//assert(m_importingNamespace);
    return m_importingNamespace;
}
void ElementImportImpl::setImportingNamespace(std::shared_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> ElementImportImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ElementImportImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> ElementImportImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ElementImportImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> ElementImportImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<ElementImport> ElementImportImpl::getThisElementImportPtr() const
{
	return m_thisElementImportPtr.lock();
}
void ElementImportImpl::setThisElementImportPtr(std::weak_ptr<ElementImport> thisElementImportPtr)
{
	m_thisElementImportPtr = thisElementImportPtr;
	setThisDirectedRelationshipPtr(thisElementImportPtr);
}
std::shared_ptr<ecore::EObject> ElementImportImpl::eContainer() const
{
	if(auto wp = m_importingNamespace.lock())
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
Any ElementImportImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_ALIAS:
			return eAny(getAlias()); //826
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
			return eAny(getImportedElement()); //827
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
			return eAny(getImportingNamespace()); //828
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_VISIBILITY:
			return eAny(getVisibility()); //829
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool ElementImportImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_ALIAS:
			return getAlias() != ""; //826
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
			return getImportedElement() != nullptr; //827
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
			return getImportingNamespace().lock() != nullptr; //828
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_VISIBILITY:
			return m_visibility != VisibilityKind::PUBLIC;; //829
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool ElementImportImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_ALIAS:
		{
			// BOOST CAST
			std::string _alias = newValue->get<std::string>();
			setAlias(_alias); //826
			return true;
		}
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<uml::PackageableElement> _importedElement = newValue->get<std::shared_ptr<uml::PackageableElement>>();
			setImportedElement(_importedElement); //827
			return true;
		}
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Namespace> _importingNamespace = newValue->get<std::shared_ptr<uml::Namespace>>();
			setImportingNamespace(_importingNamespace); //828
			return true;
		}
		case UmlPackage::ELEMENTIMPORT_EATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			VisibilityKind _visibility = newValue->get<VisibilityKind>();
			setVisibility(_visibility); //829
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void ElementImportImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void ElementImportImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("alias");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setAlias(value);
		}

		iter = attr_list.find("visibility");
		if ( iter != attr_list.end() )
		{
			VisibilityKind value = VisibilityKind::PUBLIC;
			std::string literal = iter->second;
			if (literal == "public")
			{
				value = VisibilityKind::PUBLIC;
			}
			else if (literal == "private")
			{
				value = VisibilityKind::PRIVATE;
			}
			else if (literal == "protected")
			{
				value = VisibilityKind::PROTECTED;
			}
			else if (literal == "package")
			{
				value = VisibilityKind::PACKAGE;
			}
			this->setVisibility(value);
		}
		std::shared_ptr<ecore::EClass> metaClass = this->eClass(); // get MetaClass
		iter = attr_list.find("importedElement");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("importedElement")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

	DirectedRelationshipImpl::loadAttributes(loadHandler, attr_list);
}

void ElementImportImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
{


	DirectedRelationshipImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void ElementImportImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTEDELEMENT:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::PackageableElement> _importedElement = std::dynamic_pointer_cast<uml::PackageableElement>( references.front() );
				setImportedElement(_importedElement);
			}
			
			return;
		}

		case UmlPackage::ELEMENTIMPORT_EREFERENCE_IMPORTINGNAMESPACE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Namespace> _importingNamespace = std::dynamic_pointer_cast<uml::Namespace>( references.front() );
				setImportingNamespace(_importingNamespace);
			}
			
			return;
		}
	}
	DirectedRelationshipImpl::resolveReferences(featureID, references);
}

void ElementImportImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void ElementImportImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
 
		// Add attributes
		if ( this->eIsSet(package->getElementImport_EAttribute_alias()) )
		{
			saveHandler->addAttribute("alias", this->getAlias());
		}

		if ( this->eIsSet(package->getElementImport_EAttribute_visibility()) )
		{
			VisibilityKind value = this->getVisibility();
			std::string literal = "";
			if (value == VisibilityKind::PUBLIC)
			{
				literal = "public";
			}
			else if (value == VisibilityKind::PRIVATE)
			{
				literal = "private";
			}
			else if (value == VisibilityKind::PROTECTED)
			{
				literal = "protected";
			}
			else if (value == VisibilityKind::PACKAGE)
			{
				literal = "package";
			}
			saveHandler->addAttribute("visibility", literal);
		}

		// Add references
		saveHandler->addReference("importedElement", this->getImportedElement());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

