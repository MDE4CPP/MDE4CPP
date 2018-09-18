#include "uml/impl/PackageImpl.hpp"

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

#include "uml/Class.hpp"

#include "uml/Comment.hpp"

#include "uml/Constraint.hpp"

#include "uml/Dependency.hpp"

#include "ecore/EAnnotation.hpp"

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
PackageImpl::PackageImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_nestedPackage.reset(new Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_ownedStereotype.reset(new Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedType.reset(new Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_packageMerge.reset(new Subset<uml::PackageMerge, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >()" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packagedElement.reset(new SubsetUnion<uml::PackageableElement, uml::NamedElement >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_profileApplication.reset(new Subset<uml::ProfileApplication, uml::Element >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_nestedPackage->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

	

		/*Subset*/
		m_ownedStereotype->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedType->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_packageMerge->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packagedElement->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_profileApplication->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

PackageImpl::~PackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Package "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
}


//Additional constructor for the containments back reference
			PackageImpl::PackageImpl(std::weak_ptr<uml::Namespace > par_namespace)
			:PackageImpl()
			{
			    m_namespace = par_namespace;
				m_owner = par_namespace;
			}





//Additional constructor for the containments back reference
			PackageImpl::PackageImpl(std::weak_ptr<uml::Package > par_Package, const int reference_id)
			:PackageImpl()
			{
				switch(reference_id)
				{	
				case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
					m_nestingPackage = par_Package;
					m_namespace = par_Package;
					 return;
				case UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE:
					m_owningPackage = par_Package;
					m_namespace = par_Package;
					 return;
				default:
				std::cerr << __PRETTY_FUNCTION__ <<" Reference not found in class with the given ID" << std::endl;
				}
			   
			}





//Additional constructor for the containments back reference
			PackageImpl::PackageImpl(std::weak_ptr<uml::Element > par_owner)
			:PackageImpl()
			{
			    m_owner = par_owner;
			}





//Additional constructor for the containments back reference





//Additional constructor for the containments back reference
			PackageImpl::PackageImpl(std::weak_ptr<uml::TemplateParameter > par_owningTemplateParameter)
			:PackageImpl()
			{
			    m_owningTemplateParameter = par_owningTemplateParameter;
				m_owner = par_owningTemplateParameter;
			}






PackageImpl::PackageImpl(const PackageImpl & obj):PackageImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Package "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr<Bag<uml::Dependency>> _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::NamedElement>> _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_namespace  = obj.getNamespace();

	m_nestingPackage  = obj.getNestingPackage();

	m_owner  = obj.getOwner();

	m_owningPackage  = obj.getOwningPackage();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(std::dynamic_pointer_cast<ecore::EAnnotation>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(std::dynamic_pointer_cast<uml::ElementImport>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression = std::dynamic_pointer_cast<uml::StringExpression>(obj.getNameExpression()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Package>> _nestedPackageList = obj.getNestedPackage();
	for(std::shared_ptr<uml::Package> _nestedPackage : *_nestedPackageList)
	{
		this->getNestedPackage()->add(std::shared_ptr<uml::Package>(std::dynamic_pointer_cast<uml::Package>(_nestedPackage->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nestedPackage" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(std::dynamic_pointer_cast<uml::Comment>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(std::dynamic_pointer_cast<uml::Constraint>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Stereotype>> _ownedStereotypeList = obj.getOwnedStereotype();
	for(std::shared_ptr<uml::Stereotype> _ownedStereotype : *_ownedStereotypeList)
	{
		this->getOwnedStereotype()->add(std::shared_ptr<uml::Stereotype>(std::dynamic_pointer_cast<uml::Stereotype>(_ownedStereotype->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedStereotype" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature = std::dynamic_pointer_cast<uml::TemplateSignature>(obj.getOwnedTemplateSignature()->copy());
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Type>> _ownedTypeList = obj.getOwnedType();
	for(std::shared_ptr<uml::Type> _ownedType : *_ownedTypeList)
	{
		this->getOwnedType()->add(std::shared_ptr<uml::Type>(std::dynamic_pointer_cast<uml::Type>(_ownedType->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedType" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(std::dynamic_pointer_cast<uml::PackageImport>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageMerge>> _packageMergeList = obj.getPackageMerge();
	for(std::shared_ptr<uml::PackageMerge> _packageMerge : *_packageMergeList)
	{
		this->getPackageMerge()->add(std::shared_ptr<uml::PackageMerge>(std::dynamic_pointer_cast<uml::PackageMerge>(_packageMerge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageMerge" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _packagedElementList = obj.getPackagedElement();
	for(std::shared_ptr<uml::PackageableElement> _packagedElement : *_packagedElementList)
	{
		this->getPackagedElement()->add(std::shared_ptr<uml::PackageableElement>(std::dynamic_pointer_cast<uml::PackageableElement>(_packagedElement->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packagedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ProfileApplication>> _profileApplicationList = obj.getProfileApplication();
	for(std::shared_ptr<uml::ProfileApplication> _profileApplication : *_profileApplicationList)
	{
		this->getProfileApplication()->add(std::shared_ptr<uml::ProfileApplication>(std::dynamic_pointer_cast<uml::ProfileApplication>(_profileApplication->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_profileApplication" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(std::dynamic_pointer_cast<uml::TemplateBinding>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif

		/*Subset*/
		m_nestedPackage->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_nestedPackage - Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedStereotype->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedStereotype - Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_ownedType->initSubset(m_packagedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_ownedType - Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_packageMerge->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_packageMerge - Subset<uml::PackageMerge, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	

		/*SubsetUnion*/
		m_packagedElement->initSubsetUnion(m_ownedMember);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value SubsetUnion: " << "m_packagedElement - SubsetUnion<uml::PackageableElement, uml::NamedElement >(m_ownedMember)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_profileApplication->initSubset(m_ownedElement);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_profileApplication - Subset<uml::ProfileApplication, uml::Element >(m_ownedElement)" << std::endl;
		#endif
	
	
}

std::shared_ptr<ecore::EObject>  PackageImpl::copy() const
{
	std::shared_ptr<PackageImpl> element(new PackageImpl(*this));
	element->setThisPackagePtr(element);
	return element;
}

std::shared_ptr<ecore::EClass> PackageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackage_EClass();
}

//*********************************
// Attribute Setter Getter
//*********************************
void PackageImpl::setURI(std::string _URI)
{
	m_URI = _URI;
} 

std::string PackageImpl::getURI() const 
{
	return m_URI;
}

//*********************************
// Operations
//*********************************
std::shared_ptr<Bag<uml::Stereotype> > PackageImpl::allApplicableStereotypes()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > PackageImpl::applyProfile(std::shared_ptr<uml::Profile>  profile)
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

bool PackageImpl::elements_public_or_private(Any diagnostics,std::map <   Any, Any >  context)
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

std::shared_ptr<uml::ProfileApplication> PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile>  profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ProfileApplication> PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile>  profile,bool recurse)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isModelLibrary()
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::isProfileApplied(std::shared_ptr<uml::Profile>  profile)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool PackageImpl::makesVisible(std::shared_ptr<uml::NamedElement>  el)
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> > PackageImpl::unapplyProfile(std::shared_ptr<uml::Profile>  profile)
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
std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getNestedPackage() const
{

    return m_nestedPackage;
}


std::weak_ptr<uml::Package > PackageImpl::getNestingPackage() const
{

    return m_nestingPackage;
}
void PackageImpl::setNestingPackage(std::shared_ptr<uml::Package> _nestingPackage)
{
    m_nestingPackage = _nestingPackage;
}

std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getOwnedStereotype() const
{

    return m_ownedStereotype;
}


std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/>> PackageImpl::getOwnedType() const
{

    return m_ownedType;
}


std::shared_ptr<Subset<uml::PackageMerge, uml::Element>> PackageImpl::getPackageMerge() const
{

    return m_packageMerge;
}


std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> PackageImpl::getPackagedElement() const
{

    return m_packagedElement;
}


std::shared_ptr<Subset<uml::ProfileApplication, uml::Element>> PackageImpl::getProfileApplication() const
{

    return m_profileApplication;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<Union<uml::NamedElement>> PackageImpl::getMember() const
{
	return m_member;
}
std::weak_ptr<uml::Namespace > PackageImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element>> PackageImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement>> PackageImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::weak_ptr<uml::Element > PackageImpl::getOwner() const
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
		case UmlPackage::PACKAGE_EATTRIBUTE_URI:
			return eAny(getURI()); //1321
		case UmlPackage::PACKAGE_EREFERENCE_NESTEDPACKAGE:
			return eAny(getNestedPackage()); //1322
		case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
			return eAny(getNestingPackage()); //1323
		case UmlPackage::PACKAGE_EREFERENCE_OWNEDSTEREOTYPE:
			return eAny(getOwnedStereotype()); //1324
		case UmlPackage::PACKAGE_EREFERENCE_OWNEDTYPE:
			return eAny(getOwnedType()); //1325
		case UmlPackage::PACKAGE_EREFERENCE_PACKAGEMERGE:
			return eAny(getPackageMerge()); //1326
		case UmlPackage::PACKAGE_EREFERENCE_PACKAGEDELEMENT:
			return eAny(getPackagedElement()); //1327
		case UmlPackage::PACKAGE_EREFERENCE_PROFILEAPPLICATION:
			return eAny(getProfileApplication()); //1328
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
		case UmlPackage::PACKAGE_EATTRIBUTE_URI:
			return getURI() != ""; //1321
		case UmlPackage::PACKAGE_EREFERENCE_NESTEDPACKAGE:
			return getNestedPackage() != nullptr; //1322
		case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
			return getNestingPackage().lock() != nullptr; //1323
		case UmlPackage::PACKAGE_EREFERENCE_OWNEDSTEREOTYPE:
			return getOwnedStereotype() != nullptr; //1324
		case UmlPackage::PACKAGE_EREFERENCE_OWNEDTYPE:
			return getOwnedType() != nullptr; //1325
		case UmlPackage::PACKAGE_EREFERENCE_PACKAGEMERGE:
			return getPackageMerge() != nullptr; //1326
		case UmlPackage::PACKAGE_EREFERENCE_PACKAGEDELEMENT:
			return getPackagedElement() != nullptr; //1327
		case UmlPackage::PACKAGE_EREFERENCE_PROFILEAPPLICATION:
			return getProfileApplication() != nullptr; //1328
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
		case UmlPackage::PACKAGE_EATTRIBUTE_URI:
		{
			// BOOST CAST
			std::string _URI = newValue->get<std::string>();
			setURI(_URI); //1321
			return true;
		}
		case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
		{
			// BOOST CAST
			std::shared_ptr<uml::Package> _nestingPackage = newValue->get<std::shared_ptr<uml::Package>>();
			setNestingPackage(_nestingPackage); //1323
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
	// get UmlFactory
	std::shared_ptr<uml::UmlFactory> modelFactory = uml::UmlFactory::eInstance();
	int numNodes = loadHandler->getNumOfChildNodes();
	for(int ii = 0; ii < numNodes; ii++)
	{
		loadNode(loadHandler->getNextNodeName(), loadHandler, modelFactory);
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

void PackageImpl::loadNode(std::string nodeName, std::shared_ptr<persistence::interfaces::XLoadHandler> loadHandler, std::shared_ptr<uml::UmlFactory> modelFactory)
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
			// TODO here are multiple containers of same object. Check this!
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " 'nestedPackage' has more then one back-reference Object." << std::endl;
			std::shared_ptr<ecore::EObject> nestedPackage;
				nestedPackage = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE);
				nestedPackage = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE);
			if (nestedPackage != nullptr)
			{
				loadHandler->handleChild(nestedPackage);
			}
			return;
		}

		if ( nodeName.compare("ownedStereotype") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "Stereotype";
			}
			// TODO here are multiple containers of same object. Check this!
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " 'ownedStereotype' has more then one back-reference Object." << std::endl;
			std::shared_ptr<ecore::EObject> ownedStereotype;
				ownedStereotype = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE);
				ownedStereotype = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::TYPE_EREFERENCE_PACKAGE);
			if (ownedStereotype != nullptr)
			{
				loadHandler->handleChild(ownedStereotype);
			}
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
			// TODO here are multiple containers of same object. Check this!
			std::cout << "| ERROR    | " << __PRETTY_FUNCTION__ << " 'ownedType' has more then one back-reference Object." << std::endl;
			std::shared_ptr<ecore::EObject> ownedType;
				ownedType = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE);
				ownedType = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::TYPE_EREFERENCE_PACKAGE);
			if (ownedType != nullptr)
			{
				loadHandler->handleChild(ownedType);
			}
			return;
		}

		if ( nodeName.compare("packageMerge") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "PackageMerge";
			}
			std::shared_ptr<ecore::EObject> packageMerge = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEMERGE_EREFERENCE_RECEIVINGPACKAGE);
			if (packageMerge != nullptr)
			{
				loadHandler->handleChild(packageMerge);
			}
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
			std::shared_ptr<ecore::EObject> packagedElement = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PACKAGEABLEELEMENT_EREFERENCE_OWNINGPACKAGE);
			if (packagedElement != nullptr)
			{
				loadHandler->handleChild(packagedElement);
			}
			return;
		}

		if ( nodeName.compare("profileApplication") == 0 )
		{
  			std::string typeName = loadHandler->getCurrentXSITypeName();
			if (typeName.empty())
			{
				typeName = "ProfileApplication";
			}
			std::shared_ptr<ecore::EObject> profileApplication = modelFactory->create(typeName, loadHandler->getCurrentObject(), UmlPackage::PROFILEAPPLICATION_EREFERENCE_APPLYINGPACKAGE);
			if (profileApplication != nullptr)
			{
				loadHandler->handleChild(profileApplication);
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

	NamespaceImpl::loadNode(nodeName, loadHandler, modelFactory);
	PackageableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
	TemplateableElementImpl::loadNode(nodeName, loadHandler, modelFactory);
}

void PackageImpl::resolveReferences(const int featureID, std::list<std::shared_ptr<ecore::EObject> > references)
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_EREFERENCE_NESTINGPACKAGE:
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
	
	ecore::EModelElementImpl::saveContent(saveHandler);
	ObjectImpl::saveContent(saveHandler);
	
	ecore::EObjectImpl::saveContent(saveHandler);
	
	
	
	
}

void PackageImpl::saveContent(std::shared_ptr<persistence::interfaces::XSaveHandler> saveHandler) const
{
	try
	{
		std::shared_ptr<uml::UmlPackage> package = uml::UmlPackage::eInstance();

		// Save 'nestedPackage'
		for (std::shared_ptr<uml::Package> nestedPackage : *this->getNestedPackage()) 
		{
			saveHandler->addReference(nestedPackage, "nestedPackage", nestedPackage->eClass() != package->getPackage_EClass());
		}

		// Save 'ownedStereotype'
		for (std::shared_ptr<uml::Stereotype> ownedStereotype : *this->getOwnedStereotype()) 
		{
			saveHandler->addReference(ownedStereotype, "ownedStereotype", ownedStereotype->eClass() != package->getStereotype_EClass());
		}

		// Save 'ownedType'
		for (std::shared_ptr<uml::Type> ownedType : *this->getOwnedType()) 
		{
			saveHandler->addReference(ownedType, "ownedType", ownedType->eClass() != package->getType_EClass());
		}

		// Save 'packageMerge'
		for (std::shared_ptr<uml::PackageMerge> packageMerge : *this->getPackageMerge()) 
		{
			saveHandler->addReference(packageMerge, "packageMerge", packageMerge->eClass() != package->getPackageMerge_EClass());
		}

		// Save 'profileApplication'
		for (std::shared_ptr<uml::ProfileApplication> profileApplication : *this->getProfileApplication()) 
		{
			saveHandler->addReference(profileApplication, "profileApplication", profileApplication->eClass() != package->getProfileApplication_EClass());
		}
	
 
		// Add attributes
		if ( this->eIsSet(package->getPackage_EAttribute_uRI()) )
		{
			saveHandler->addAttribute("URI", this->getURI());
		}


		//
		// Add new tags (from references)
		//
		std::shared_ptr<ecore::EClass> metaClass = this->eClass();
		// Save 'packagedElement'
		std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement>> list_packagedElement = this->getPackagedElement();
		for (std::shared_ptr<uml::PackageableElement> packagedElement : *list_packagedElement) 
		{
			saveHandler->addReference(packagedElement, "packagedElement", packagedElement->eClass() != package->getPackageableElement_EClass());
		}
	}
	catch (std::exception& e)
	{
		std::cout << "| ERROR    | " << e.what() << std::endl;
	}
}

