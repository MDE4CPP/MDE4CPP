#include "uml/impl/PackageImportImpl.hpp"

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

#include "uml/DirectedRelationship.hpp"

#include "uml/Element.hpp"

#include "uml/Namespace.hpp"

#include "uml/Package.hpp"

//Factories an Package includes
#include "uml/Impl/UmlFactoryImpl.hpp"
#include "uml/Impl/UmlPackageImpl.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImportImpl::PackageImportImpl()
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

PackageImportImpl::~PackageImportImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete PackageImport "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Namespace > par_importingNamespace)
			:PackageImportImpl()
			{
			    m_importingNamespace = par_importingNamespace;
				m_owner = par_importingNamespace;
			}


//Additional constructor for the containments back reference
			PackageImportImpl::PackageImportImpl(std::weak_ptr<uml::Element > par_owner)
			:PackageImportImpl()
			{
			    m_owner = par_owner;
			}



PackageImportImpl::PackageImportImpl(const PackageImportImpl & obj):PackageImportImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy PackageImport "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	m_importingNamespace  = obj.getImportingNamespace();

	m_owner  = obj.getOwner();

	std::shared_ptr<Union<uml::Element>> _relatedElement = obj.getRelatedElement();
	m_relatedElement.reset(new Union<uml::Element>(*(obj.getRelatedElement().get())));


	//Clone references with containment (deep copy)

	if(obj.getImportedPackage()!=nullptr)
	{
		m_importedPackage = std::dynamic_pointer_cast<uml::Package>(obj.getImportedPackage()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedPackage" << std::endl;
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

std::shared_ptr<ecore::EObject>  PackageImportImpl::copy() const
{
	std::shared_ptr<PackageImportImpl> element(new PackageImportImpl(*this));
	element->setThisPackageImportPtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PackageImportImpl::eStaticClass() const
{
	return uml::UmlPackage::eInstance()->getPackageImport_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PackageImportImpl::setVisibility(uml::VisibilityKind _visibility)
{
	m_visibility = _visibility;
} 

uml::VisibilityKind PackageImportImpl::getVisibility() const 
{
	return m_visibility;
}

//*********************************
// Operations
//*********************************
bool PackageImportImpl::public_or_private(Any diagnostics,std::map <   Any, Any >  context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Package > PackageImportImpl::getImportedPackage() const
{
//assert(m_importedPackage);
    return m_importedPackage;
}
void PackageImportImpl::setImportedPackage(std::shared_ptr<uml::Package> _importedPackage)
{
    m_importedPackage = _importedPackage;
}

std::weak_ptr<uml::Namespace > PackageImportImpl::getImportingNamespace() const
{
//assert(m_importingNamespace);
    return m_importingNamespace;
}
void PackageImportImpl::setImportingNamespace(std::shared_ptr<uml::Namespace> _importingNamespace)
{
    m_importingNamespace = _importingNamespace;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::Element>> PackageImportImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > PackageImportImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::Element>> PackageImportImpl::getRelatedElement() const
{
	return m_relatedElement;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> PackageImportImpl::getSource() const
{
	return m_source;
}
std::shared_ptr<SubsetUnion<uml::Element, uml::Element>> PackageImportImpl::getTarget() const
{
	return m_target;
}


std::shared_ptr<PackageImport> PackageImportImpl::getThisPackageImportPtr() const
{
	return m_thisPackageImportPtr.lock();
}
void PackageImportImpl::setThisPackageImportPtr(std::weak_ptr<PackageImport> thisPackageImportPtr)
{
	m_thisPackageImportPtr = thisPackageImportPtr;
	setThisDirectedRelationshipPtr(thisPackageImportPtr);
}
std::shared_ptr<ecore::EObject> PackageImportImpl::eContainer() const
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
Any PackageImportImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getImportedPackage())); //1726
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
			return eAny(std::dynamic_pointer_cast<ecore::EObject>(getImportingNamespace().lock())); //1727
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
			return eAny(getVisibility()); //1728
	}
	return DirectedRelationshipImpl::eGet(featureID, resolve, coreType);
}
bool PackageImportImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
			return getImportedPackage() != nullptr; //1726
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
			return getImportingNamespace().lock() != nullptr; //1727
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
			return m_visibility != VisibilityKind::PUBLIC;; //1728
	}
	return DirectedRelationshipImpl::internalEIsSet(featureID);
}
bool PackageImportImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _importedPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setImportedPackage(_importedPackage); //1726
			return true;
		}
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Namespace> _importingNamespace = std::dynamic_pointer_cast<uml::Namespace>(_temp);
			setImportingNamespace(_importingNamespace); //1727
			return true;
		}
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_VISIBILITY:
		{
			// BOOST CAST
			uml::VisibilityKind _visibility = newValue->get<uml::VisibilityKind>();
			setVisibility(_visibility); //1728
			return true;
		}
	}

	return DirectedRelationshipImpl::eSet(featureID, newValue);
}

//*********************************
// Persistence Functions
//*********************************
void PackageImportImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageImportImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("visibility");
		if ( iter != attr_list.end() )
		{
			uml::VisibilityKind value = VisibilityKind::PUBLIC;
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
		iter = attr_list.find("importedPackage");
		if ( iter != attr_list.end() )
		{
			// add unresolvedReference to loadHandler's list
			loadHandler->addUnresolvedReference(iter->second, loadHandler->getCurrentObject(), metaClass->getEStructuralFeature("importedPackage")); // TODO use getEStructuralFeature() with id, for faster access to EStructuralFeature
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

void PackageImportImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{
	std::shared_ptr<uml::UmlFactory> modelFactory=uml::UmlFactory::eInstance();

	//load BasePackage Nodes
	DirectedRelationshipImpl::loadNode(nodeName, loadHandler);
}

void PackageImportImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTEDPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _importedPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setImportedPackage(_importedPackage);
			}
			
			return;
		}

		case uml::UmlPackage::PACKAGEIMPORT_ATTRIBUTE_IMPORTINGNAMESPACE:
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

void PackageImportImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	DirectedRelationshipImpl::saveContent(saveHandler);
	
	RelationshipImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void PackageImportImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

	
		// Add attributes
		if ( this->eIsSet(package->getPackageImport_Attribute_visibility()) )
		{
			uml::VisibilityKind value = this->getVisibility();
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
		saveHandler->addReference("importedPackage", this->getImportedPackage());

	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

