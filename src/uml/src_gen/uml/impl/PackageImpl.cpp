#include "uml/impl/PackageImpl.hpp"

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


#include "uml/Class.hpp"
#include "uml/Comment.hpp"
#include "uml/Constraint.hpp"
#include "uml/Dependency.hpp"
#include "ecore/EObject.hpp"
#include "uml/Element.hpp"
#include "uml/ElementImport.hpp"
#include "uml/Enumeration.hpp"
#include "uml/Interface.hpp"
#include "uml/NamedElement.hpp"
#include "uml/Namespace.hpp"
#include "uml/Package.hpp"
#include "uml/PackageImport.hpp"
#include "uml/PackageMerge.hpp"
#include "uml/PackageableElement.hpp"
#include "uml/PrimitiveType.hpp"
#include "uml/Profile.hpp"
#include "uml/ProfileApplication.hpp"
#include "uml/Stereotype.hpp"
#include "uml/StringExpression.hpp"
#include "uml/TemplateBinding.hpp"
#include "uml/TemplateParameter.hpp"
#include "uml/TemplateSignature.hpp"
#include "uml/TemplateableElement.hpp"
#include "uml/Type.hpp"

//Factories an Package includes
#include "ecore/ecorePackage.hpp"
#include "uml/umlPackage.hpp"


#include "ecore/EAttribute.hpp"
#include "ecore/EStructuralFeature.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
PackageImpl::PackageImpl()
{	
	/*
	NOTE: Due to virtual inheritance, base class constrcutors may not be called correctly
	*/
}

PackageImpl::~PackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Package "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}

//Additional constructor for the containments back reference
PackageImpl::PackageImpl(std::weak_ptr<uml::Namespace> par_namespace)
:PackageImpl()
{
	m_namespace = par_namespace;
	m_owner = par_namespace;
}

//Additional constructor for the containments back reference
PackageImpl::PackageImpl(std::weak_ptr<uml::Package> par_Package, const int reference_id)
:PackageImpl()
{
	switch(reference_id)
	{	
	case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
		m_nestingPackage = par_Package;
		m_namespace = par_Package;
		 return;
	case uml::umlPackage::PACKAGEABLEELEMENT_ATTRIBUTE_OWNINGPACKAGE:
		m_owningPackage = par_Package;
		m_namespace = par_Package;
		 return;
	default:
	std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
	}
   
}

//Additional constructor for the containments back reference
PackageImpl::PackageImpl(std::weak_ptr<uml::Element> par_owner)
:PackageImpl()
{
	m_owner = par_owner;
}


//Additional constructor for the containments back reference
PackageImpl::PackageImpl(std::weak_ptr<uml::TemplateParameter> par_owningTemplateParameter)
:PackageImpl()
{
	m_owningTemplateParameter = par_owningTemplateParameter;
	m_owner = par_owningTemplateParameter;
}

PackageImpl::PackageImpl(const PackageImpl & obj): PackageImpl()
{
	*this = obj;
}

PackageImpl& PackageImpl::operator=(const PackageImpl & obj)
{
	//call overloaded =Operator for each base class
	NamespaceImpl::operator=(obj);
	PackageableElementImpl::operator=(obj);
	TemplateableElementImpl::operator=(obj);
	Package::operator=(obj);

	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Package "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	//Clone Attributes with (deep copy)
	m_URI = obj.getURI();

	//copy references with no containment (soft copy)
	m_nestingPackage  = obj.getNestingPackage();
	//Clone references with containment (deep copy)
	std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> nestedPackageContainer = getNestedPackage();
	if(nullptr != nestedPackageContainer )
	{
		int size = nestedPackageContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _nestedPackage=(*nestedPackageContainer)[i];
			if(nullptr != _nestedPackage)
			{
				nestedPackageContainer->push_back(std::dynamic_pointer_cast<uml::Package>(_nestedPackage->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container nestedPackage."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr nestedPackage."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> ownedStereotypeContainer = getOwnedStereotype();
	if(nullptr != ownedStereotypeContainer )
	{
		int size = ownedStereotypeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedStereotype=(*ownedStereotypeContainer)[i];
			if(nullptr != _ownedStereotype)
			{
				ownedStereotypeContainer->push_back(std::dynamic_pointer_cast<uml::Stereotype>(_ownedStereotype->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedStereotype."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedStereotype."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> ownedTypeContainer = getOwnedType();
	if(nullptr != ownedTypeContainer )
	{
		int size = ownedTypeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _ownedType=(*ownedTypeContainer)[i];
			if(nullptr != _ownedType)
			{
				ownedTypeContainer->push_back(std::dynamic_pointer_cast<uml::Type>(_ownedType->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container ownedType."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr ownedType."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> packageMergeContainer = getPackageMerge();
	if(nullptr != packageMergeContainer )
	{
		int size = packageMergeContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _packageMerge=(*packageMergeContainer)[i];
			if(nullptr != _packageMerge)
			{
				packageMergeContainer->push_back(std::dynamic_pointer_cast<uml::PackageMerge>(_packageMerge->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container packageMerge."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr packageMerge."<< std::endl;)
	}
	std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> packagedElementContainer = getPackagedElement();
	if(nullptr != packagedElementContainer )
	{
		int size = packagedElementContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _packagedElement=(*packagedElementContainer)[i];
			if(nullptr != _packagedElement)
			{
				packagedElementContainer->push_back(std::dynamic_pointer_cast<uml::PackageableElement>(_packagedElement->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container packagedElement."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr packagedElement."<< std::endl;)
	}
	std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> profileApplicationContainer = getProfileApplication();
	if(nullptr != profileApplicationContainer )
	{
		int size = profileApplicationContainer->size();
		for(int i=0; i<size ; i++)
		{
			auto _profileApplication=(*profileApplicationContainer)[i];
			if(nullptr != _profileApplication)
			{
				profileApplicationContainer->push_back(std::dynamic_pointer_cast<uml::ProfileApplication>(_profileApplication->copy()));
			}
			else
			{
				DEBUG_MESSAGE(std::cout << "Warning: nullptr in container profileApplication."<< std::endl;)
			}
		}
	}
	else
	{
		DEBUG_MESSAGE(std::cout << "Warning: container is nullptr profileApplication."<< std::endl;)
	}
	/*Subset*/
	m_nestedPackage->initSubset(getPackagedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedStereotype->initSubset(getPackagedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_ownedType->initSubset(getPackagedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
	#endif
	
	/*Subset*/
	m_packageMerge->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	/*SubsetUnion*/
	m_packagedElement->initSubsetUnion(getOwnedMember());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >(getOwnedMember())" << std::endl;
	#endif
	
	/*Subset*/
	m_profileApplication->initSubset(getOwnedElement());
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Initialising value Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >(getOwnedElement())" << std::endl;
	#endif
	
	return *this;
}

std::shared_ptr<ecore::EObject> PackageImpl::copy() const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl());
	*element =(*this);
	element->setThisPackagePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PackageImpl::eStaticClass() const
{
	return uml::umlPackage::eInstance()->getPackage_Class();
}

//*********************************
// Attribute Setter Getter
//*********************************
/*
Getter & Setter for attribute URI
*/
std::string PackageImpl::getURI() const 
{
	return m_URI;
}
void PackageImpl::setURI(std::string _URI)
{
	m_URI = _URI;
} 


//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Stereotype> > PackageImpl::allApplicableStereotypes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > PackageImpl::applyProfile(std::shared_ptr<uml::Profile> profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> PackageImpl::containingProfile()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> PackageImpl::createOwnedClass(std::string name,bool isAbstract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Enumeration> PackageImpl::createOwnedEnumeration(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Interface> PackageImpl::createOwnedInterface(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PrimitiveType> PackageImpl::createOwnedPrimitiveType(std::string name)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> PackageImpl::createOwnedStereotype(std::string name,bool isAbstract)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::elements_public_or_private(Any diagnostics,std::shared_ptr<std::map < Any, Any>> context)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Profile> > PackageImpl::getAllAppliedProfiles()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ProfileApplication> > PackageImpl::getAllProfileApplications()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> PackageImpl::getAppliedProfile(std::string qualifiedName)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> PackageImpl::getAppliedProfile(std::string qualifiedName,bool recurse)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Profile> > PackageImpl::getAppliedProfiles()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Package> > PackageImpl::getNestedPackages()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> > PackageImpl::getOwnedStereotypes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> > PackageImpl::getOwnedTypes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ProfileApplication> PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile> profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ProfileApplication> PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile> profile,bool recurse)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isModelLibrary()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isProfileApplied(std::shared_ptr<uml::Profile> profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::makesVisible(std::shared_ptr<uml::NamedElement> el)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > PackageImpl::unapplyProfile(std::shared_ptr<uml::Profile> profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> > PackageImpl::visibleMembers()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
/*
Getter & Setter for reference nestedPackage
*/
std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getNestedPackage() const
{
	if(m_nestedPackage == nullptr)
	{
		/*Subset*/
		m_nestedPackage.reset(new Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_nestedPackage->initSubset(getPackagedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
		#endif
		
	}

    return m_nestedPackage;
}



/*
Getter & Setter for reference nestingPackage
*/
std::weak_ptr<uml::Package> PackageImpl::getNestingPackage() const
{

    return m_nestingPackage;
}
void PackageImpl::setNestingPackage(std::weak_ptr<uml::Package> _nestingPackage)
{
    m_nestingPackage = _nestingPackage;
}


/*
Getter & Setter for reference ownedStereotype
*/
std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getOwnedStereotype() const
{
	if(m_ownedStereotype == nullptr)
	{
		/*Subset*/
		m_ownedStereotype.reset(new Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedStereotype->initSubset(getPackagedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
		#endif
		
	}

    return m_ownedStereotype;
}



/*
Getter & Setter for reference ownedType
*/
std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getOwnedType() const
{
	if(m_ownedType == nullptr)
	{
		/*Subset*/
		m_ownedType.reset(new Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
		
		/*Subset*/
		m_ownedType->initSubset(getPackagedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(getPackagedElement())" << std::endl;
		#endif
		
	}

    return m_ownedType;
}



/*
Getter & Setter for reference packageMerge
*/
std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> PackageImpl::getPackageMerge() const
{
	if(m_packageMerge == nullptr)
	{
		/*Subset*/
		m_packageMerge.reset(new Subset<uml::PackageMerge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_packageMerge->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_packageMerge;
}



/*
Getter & Setter for reference packagedElement
*/
std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> PackageImpl::getPackagedElement() const
{
	if(m_packagedElement == nullptr)
	{
		/*SubsetUnion*/
		m_packagedElement.reset(new SubsetUnion<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_packagedElement->initSubsetUnion(getOwnedMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >(getOwnedMember())" << std::endl;
		#endif
		
	}

    return m_packagedElement;
}



/*
Getter & Setter for reference profileApplication
*/
std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> PackageImpl::getProfileApplication() const
{
	if(m_profileApplication == nullptr)
	{
		/*Subset*/
		m_profileApplication.reset(new Subset<uml::ProfileApplication, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >()" << std::endl;
		#endif
		
		/*Subset*/
		m_profileApplication->initSubset(getOwnedElement());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >(getOwnedElement())" << std::endl;
		#endif
		
	}

    return m_profileApplication;
}



//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> PackageImpl::getMember() const
{
	if(m_member == nullptr)
	{
		/*Union*/
		m_member.reset(new Union<uml::NamedElement>());
			#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising Union: " << "m_member - Union<uml::NamedElement>()" << std::endl;
		#endif
		
		
	}
	return m_member;
}

std::weak_ptr<uml::Namespace> PackageImpl::getNamespace() const
{
	return m_namespace;
}

std::shared_ptr<Union<uml::Element>> PackageImpl::getOwnedElement() const
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

std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> PackageImpl::getOwnedMember() const
{
	if(m_ownedMember == nullptr)
	{
		/*SubsetUnion*/
		m_ownedMember.reset(new SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >()" << std::endl;
		#endif
		
		/*SubsetUnion*/
		m_ownedMember->initSubsetUnion(getOwnedElement(),getMember());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_ownedMember - SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement >(getOwnedElement(),getMember())" << std::endl;
		#endif
		
	}
	return m_ownedMember;
}

std::weak_ptr<uml::Element> PackageImpl::getOwner() const
{
	return m_owner;
}




std::shared_ptr<Package> PackageImpl::getThisPackagePtr() const
{
	return m_thisPackagePtr.lock();
}
void PackageImpl::setThisPackagePtr(std::weak_ptr<Package> thisPackagePtr)
{
	m_thisPackagePtr = thisPackagePtr;
	setThisNamespacePtr(thisPackagePtr);
	setThisPackageableElementPtr(thisPackagePtr);
	setThisTemplateableElementPtr(thisPackagePtr);
}
std::shared_ptr<ecore::EObject> PackageImpl::eContainer() const
{
	if(auto wp = m_namespace.lock())
	{
		return wp;
	}

	if(auto wp = m_nestingPackage.lock())
	{
		return wp;
	}
	if(auto wp = m_owningPackage.lock())
	{
		return wp;
	}

	if(auto wp = m_owner.lock())
	{
		return wp;
	}


	if(auto wp = m_owningTemplateParameter.lock())
	{
		return wp;
	}
	return nullptr;
}

//*********************************
// Structural Feature Getter/Setter
//*********************************
Any PackageImpl::eGet(int featureID, bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGE_ATTRIBUTE_URI:
			return eAny(getURI()); //17020
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTEDPACKAGE:
		{
			return eAny(getNestedPackage()); //17021			
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
			return eAny(getNestingPackage().lock()); //17022
		case uml::umlPackage::PACKAGE_ATTRIBUTE_OWNEDSTEREOTYPE:
		{
			return eAny(getOwnedStereotype()); //17023			
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_OWNEDTYPE:
		{
			return eAny(getOwnedType()); //17024			
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEMERGE:
		{
			return eAny(getPackageMerge()); //17025			
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEDELEMENT:
		{
			return eAny(getPackagedElement()); //17026			
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PROFILEAPPLICATION:
		{
			return eAny(getProfileApplication()); //17027			
		}
	}
	Any result;
	result = NamespaceImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = PackageableElementImpl::eGet(featureID, resolve, coreType);
	if (!result->isEmpty())
	{
		return result;
	}
	result = TemplateableElementImpl::eGet(featureID, resolve, coreType);
	return result;
}
bool PackageImpl::internalEIsSet(int featureID) const
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGE_ATTRIBUTE_URI:
			return getURI() != ""; //17020
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTEDPACKAGE:
			return getNestedPackage() != nullptr; //17021
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
			return getNestingPackage().lock() != nullptr; //17022
		case uml::umlPackage::PACKAGE_ATTRIBUTE_OWNEDSTEREOTYPE:
			return getOwnedStereotype() != nullptr; //17023
		case uml::umlPackage::PACKAGE_ATTRIBUTE_OWNEDTYPE:
			return getOwnedType() != nullptr; //17024
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEMERGE:
			return getPackageMerge() != nullptr; //17025
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEDELEMENT:
			return getPackagedElement() != nullptr; //17026
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PROFILEAPPLICATION:
			return getProfileApplication() != nullptr; //17027
	}
	bool result = false;
	result = NamespaceImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::internalEIsSet(featureID);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::internalEIsSet(featureID);
	return result;
}
bool PackageImpl::eSet(int featureID, Any newValue)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGE_ATTRIBUTE_URI:
		{
			// BOOST CAST
			std::string _URI = newValue->get<std::string>();
			setURI(_URI); //17020
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTEDPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Package>> nestedPackageList(new Bag<uml::Package>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				nestedPackageList->add(std::dynamic_pointer_cast<uml::Package>(*iter));
				iter++;
			}
			
			Bag<uml::Package>::iterator iterNestedPackage = m_nestedPackage->begin();
			Bag<uml::Package>::iterator endNestedPackage = m_nestedPackage->end();
			while (iterNestedPackage != endNestedPackage)
			{
				if (nestedPackageList->find(*iterNestedPackage) == -1)
				{
					m_nestedPackage->erase(*iterNestedPackage);
				}
				iterNestedPackage++;
			}
 
			iterNestedPackage = nestedPackageList->begin();
			endNestedPackage = nestedPackageList->end();
			while (iterNestedPackage != endNestedPackage)
			{
				if (m_nestedPackage->find(*iterNestedPackage) == -1)
				{
					m_nestedPackage->add(*iterNestedPackage);
				}
				iterNestedPackage++;			
			}
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<ecore::EObject> _temp = newValue->get<std::shared_ptr<ecore::EObject>>();
			std::shared_ptr<uml::Package> _nestingPackage = std::dynamic_pointer_cast<uml::Package>(_temp);
			setNestingPackage(_nestingPackage); //17022
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_OWNEDTYPE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::Type>> ownedTypeList(new Bag<uml::Type>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				ownedTypeList->add(std::dynamic_pointer_cast<uml::Type>(*iter));
				iter++;
			}
			
			Bag<uml::Type>::iterator iterOwnedType = m_ownedType->begin();
			Bag<uml::Type>::iterator endOwnedType = m_ownedType->end();
			while (iterOwnedType != endOwnedType)
			{
				if (ownedTypeList->find(*iterOwnedType) == -1)
				{
					m_ownedType->erase(*iterOwnedType);
				}
				iterOwnedType++;
			}
 
			iterOwnedType = ownedTypeList->begin();
			endOwnedType = ownedTypeList->end();
			while (iterOwnedType != endOwnedType)
			{
				if (m_ownedType->find(*iterOwnedType) == -1)
				{
					m_ownedType->add(*iterOwnedType);
				}
				iterOwnedType++;			
			}
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEMERGE:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PackageMerge>> packageMergeList(new Bag<uml::PackageMerge>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				packageMergeList->add(std::dynamic_pointer_cast<uml::PackageMerge>(*iter));
				iter++;
			}
			
			Bag<uml::PackageMerge>::iterator iterPackageMerge = m_packageMerge->begin();
			Bag<uml::PackageMerge>::iterator endPackageMerge = m_packageMerge->end();
			while (iterPackageMerge != endPackageMerge)
			{
				if (packageMergeList->find(*iterPackageMerge) == -1)
				{
					m_packageMerge->erase(*iterPackageMerge);
				}
				iterPackageMerge++;
			}
 
			iterPackageMerge = packageMergeList->begin();
			endPackageMerge = packageMergeList->end();
			while (iterPackageMerge != endPackageMerge)
			{
				if (m_packageMerge->find(*iterPackageMerge) == -1)
				{
					m_packageMerge->add(*iterPackageMerge);
				}
				iterPackageMerge++;			
			}
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PACKAGEDELEMENT:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::PackageableElement>> packagedElementList(new Bag<uml::PackageableElement>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				packagedElementList->add(std::dynamic_pointer_cast<uml::PackageableElement>(*iter));
				iter++;
			}
			
			Bag<uml::PackageableElement>::iterator iterPackagedElement = m_packagedElement->begin();
			Bag<uml::PackageableElement>::iterator endPackagedElement = m_packagedElement->end();
			while (iterPackagedElement != endPackagedElement)
			{
				if (packagedElementList->find(*iterPackagedElement) == -1)
				{
					m_packagedElement->erase(*iterPackagedElement);
				}
				iterPackagedElement++;
			}
 
			iterPackagedElement = packagedElementList->begin();
			endPackagedElement = packagedElementList->end();
			while (iterPackagedElement != endPackagedElement)
			{
				if (m_packagedElement->find(*iterPackagedElement) == -1)
				{
					m_packagedElement->add(*iterPackagedElement);
				}
				iterPackagedElement++;			
			}
			return true;
		}
		case uml::umlPackage::PACKAGE_ATTRIBUTE_PROFILEAPPLICATION:
		{
			// BOOST CAST
			std::shared_ptr<Bag<ecore::EObject>> tempObjectList = newValue->get<std::shared_ptr<Bag<ecore::EObject>>>();
			std::shared_ptr<Bag<uml::ProfileApplication>> profileApplicationList(new Bag<uml::ProfileApplication>());
			Bag<ecore::EObject>::iterator iter = tempObjectList->begin();
			Bag<ecore::EObject>::iterator end = tempObjectList->end();
			while (iter != end)
			{
				profileApplicationList->add(std::dynamic_pointer_cast<uml::ProfileApplication>(*iter));
				iter++;
			}
			
			Bag<uml::ProfileApplication>::iterator iterProfileApplication = m_profileApplication->begin();
			Bag<uml::ProfileApplication>::iterator endProfileApplication = m_profileApplication->end();
			while (iterProfileApplication != endProfileApplication)
			{
				if (profileApplicationList->find(*iterProfileApplication) == -1)
				{
					m_profileApplication->erase(*iterProfileApplication);
				}
				iterProfileApplication++;
			}
 
			iterProfileApplication = profileApplicationList->begin();
			endProfileApplication = profileApplicationList->end();
			while (iterProfileApplication != endProfileApplication)
			{
				if (m_profileApplication->find(*iterProfileApplication) == -1)
				{
					m_profileApplication->add(*iterProfileApplication);
				}
				iterProfileApplication++;			
			}
			return true;
		}
	}

	bool result = false;
	result = NamespaceImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = PackageableElementImpl::eSet(featureID, newValue);
	if (result)
	{
		return result;
	}
	result = TemplateableElementImpl::eSet(featureID, newValue);
	return result;
}

//*********************************
// Persistence Functions
//*********************************
void PackageImpl::load(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
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

void PackageImpl::loadAttributes(std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::map<std::string, std::string> attr_list)
{
	try
	{
		std::map<std::string, std::string>::const_iterator iter;
	
		iter = attr_list.find("URI");
		if ( iter != attr_list.end() )
		{
			// this attribute is a 'std::string'
			std::string value;
			value = iter->second;
			this->setURI(value);
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

	NamespaceImpl::loadAttributes(loadHandler, attr_list);
	PackageableElementImpl::loadAttributes(loadHandler, attr_list);
	TemplateableElementImpl::loadAttributes(loadHandler, attr_list);
}

void PackageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler)
{

	try
	{
		if ( nodeName.compare("nestedPackage") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Package";
			}
			loadHandler->handleChildContainer<uml::Package>(this->getNestedPackage());  

			return; 
		}

		if ( nodeName.compare("ownedStereotype") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Stereotype";
			}
			loadHandler->handleChildContainer<uml::Stereotype>(this->getOwnedStereotype());  

			return; 
		}

		if ( nodeName.compare("ownedType") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::Type>(this->getOwnedType());  

			return; 
		}

		if ( nodeName.compare("packageMerge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "PackageMerge";
			}
			loadHandler->handleChildContainer<uml::PackageMerge>(this->getPackageMerge());  

			return; 
		}

		if ( nodeName.compare("packagedElement") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				std::cout << "| WARNING    | type if an eClassifiers node it empty" << std::endl;
				return; // no type name given and reference type is abstract
			}
			loadHandler->handleChildContainer<uml::PackageableElement>(this->getPackagedElement());  

			return; 
		}

		if ( nodeName.compare("profileApplication") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ProfileApplication";
			}
			loadHandler->handleChildContainer<uml::ProfileApplication>(this->getProfileApplication());  

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
	//load BasePackage Nodes
	NamespaceImpl::loadNode(nodeName, loadHandler);
	PackageableElementImpl::loadNode(nodeName, loadHandler);
	TemplateableElementImpl::loadNode(nodeName, loadHandler);
}

void PackageImpl::resolveReferences(const int featureID, std::vector<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case uml::umlPackage::PACKAGE_ATTRIBUTE_NESTINGPACKAGE:
		{
			if (references.size() == 1)
			{
				// Cast object to correct type
				std::shared_ptr<uml::Package> _nestingPackage = std::dynamic_pointer_cast<uml::Package>( references.front() );
				setNestingPackage(_nestingPackage);
			}
			
			return;
		}
	}
	NamespaceImpl::resolveReferences(featureID, references);
	PackageableElementImpl::resolveReferences(featureID, references);
	TemplateableElementImpl::resolveReferences(featureID, references);
}

void PackageImpl::save(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	saveContent(saveHandler);

	NamespaceImpl::saveContent(saveHandler);
	PackageableElementImpl::saveContent(saveHandler);
	TemplateableElementImpl::saveContent(saveHandler);
	
	NamedElementImpl::saveContent(saveHandler);
	ParameterableElementImpl::saveContent(saveHandler);
	
	ElementImpl::saveContent(saveHandler);
	
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void PackageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::umlPackage> package = uml::umlPackage::eInstance();
		// Save 'nestedPackage'
		for (std::shared_ptr<uml::Package> nestedPackage : *this->getNestedPackage()) 
		{
			saveHandler->addReference(nestedPackage, "nestedPackage", nestedPackage->eClass() != package->getPackage_Class());
		}

		// Save 'ownedStereotype'
		for (std::shared_ptr<uml::Stereotype> ownedStereotype : *this->getOwnedStereotype()) 
		{
			saveHandler->addReference(ownedStereotype, "ownedStereotype", ownedStereotype->eClass() != package->getStereotype_Class());
		}

		// Save 'ownedType'
		for (std::shared_ptr<uml::Type> ownedType : *this->getOwnedType()) 
		{
			saveHandler->addReference(ownedType, "ownedType", ownedType->eClass() != package->getType_Class());
		}

		// Save 'packageMerge'
		for (std::shared_ptr<uml::PackageMerge> packageMerge : *this->getPackageMerge()) 
		{
			saveHandler->addReference(packageMerge, "packageMerge", packageMerge->eClass() != package->getPackageMerge_Class());
		}

		// Save 'profileApplication'
		for (std::shared_ptr<uml::ProfileApplication> profileApplication : *this->getProfileApplication()) 
		{
			saveHandler->addReference(profileApplication, "profileApplication", profileApplication->eClass() != package->getProfileApplication_Class());
		}
		// Add attributes
		if ( this->eIsSet(package->getPackage_Attribute_uRI()) )
		{
			saveHandler->addAttribute("URI", this->getURI());
		}
		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'packagedElement'

		saveHandler->addReferences<uml::PackageableElement>("packagedElement", this->getPackagedElement());
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

