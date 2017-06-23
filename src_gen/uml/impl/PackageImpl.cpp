#include "PackageImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

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
		/*Subset*/
		m_nestedPackage.reset(new Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement));//(m_packagedElement));
	
	
	
		/*Subset*/
		m_ownedStereotype.reset(new Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement));//(m_packagedElement));
	
	
		/*Subset*/
		m_ownedType.reset(new Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ >(m_packagedElement));//(m_packagedElement));
	
	
		/*Subset*/
		m_packageMerge.reset(new Subset<uml::PackageMerge, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
		/*SubsetUnion*/
		m_packagedElement.reset(new SubsetUnion<uml::PackageableElement, uml::NamedElement >(m_ownedMember));// ownedMember));
	
	
		/*Subset*/
		m_profileApplication.reset(new Subset<uml::ProfileApplication, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
}

PackageImpl::~PackageImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Package "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

PackageImpl::PackageImpl(const PackageImpl & obj)
{
	//create copy of all Attributes
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ > >
	 _nestedPackage = obj.getNestedPackage();
	m_nestedPackage.reset(new 		Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ > 
	(*(obj.getNestedPackage().get())));// this->getNestedPackage()->insert(this->getNestedPackage()->end(), _nestedPackage->begin(), _nestedPackage->end());

	m_nestingPackage  = obj.getNestingPackage();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

			std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ > >
	 _ownedStereotype = obj.getOwnedStereotype();
	m_ownedStereotype.reset(new 		Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ > 
	(*(obj.getOwnedStereotype().get())));// this->getOwnedStereotype()->insert(this->getOwnedStereotype()->end(), _ownedStereotype->begin(), _ownedStereotype->end());

			std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ > >
	 _ownedType = obj.getOwnedType();
	m_ownedType.reset(new 		Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ > 
	(*(obj.getOwnedType().get())));// this->getOwnedType()->insert(this->getOwnedType()->end(), _ownedType->begin(), _ownedType->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


	//clone containt lists
	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<Bag<uml::PackageMerge>> _packageMergeList = obj.getPackageMerge();
	for(std::shared_ptr<uml::PackageMerge> _packageMerge : *_packageMergeList)
	{
		this->getPackageMerge()->add(std::shared_ptr<uml::PackageMerge>(dynamic_cast<uml::PackageMerge*>(_packageMerge->copy())));
	}
	std::shared_ptr<Bag<uml::PackageableElement>> _packagedElementList = obj.getPackagedElement();
	for(std::shared_ptr<uml::PackageableElement> _packagedElement : *_packagedElementList)
	{
		this->getPackagedElement()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_packagedElement->copy())));
	}
	std::shared_ptr<Bag<uml::ProfileApplication>> _profileApplicationList = obj.getProfileApplication();
	for(std::shared_ptr<uml::ProfileApplication> _profileApplication : *_profileApplicationList)
	{
		this->getProfileApplication()->add(std::shared_ptr<uml::ProfileApplication>(dynamic_cast<uml::ProfileApplication*>(_profileApplication->copy())));
	}
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
}

ecore::EObject *  PackageImpl::copy() const
{
	return new PackageImpl(*this);
}

std::shared_ptr<ecore::EClass> PackageImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getPackage();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void PackageImpl::setURI (std::string _URI)
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
std::shared_ptr<Bag<uml::Stereotype> >
 PackageImpl::allApplicableStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> >
 PackageImpl::applyProfile(std::shared_ptr<uml::Profile>  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> 
 PackageImpl::containingProfile() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Class> 
 PackageImpl::createOwnedClass(std::string name,bool isAbstract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Enumeration> 
 PackageImpl::createOwnedEnumeration(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Interface> 
 PackageImpl::createOwnedInterface(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::PrimitiveType> 
 PackageImpl::createOwnedPrimitiveType(std::string name) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Stereotype> 
 PackageImpl::createOwnedStereotype(std::string name,bool isAbstract) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PackageImpl::elements_public_or_private(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Profile> >
 PackageImpl::getAllAppliedProfiles() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::ProfileApplication> >
 PackageImpl::getAllProfileApplications() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> 
 PackageImpl::getAppliedProfile(std::string qualifiedName) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> 
 PackageImpl::getAppliedProfile(std::string qualifiedName,bool recurse) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Profile> >
 PackageImpl::getAppliedProfiles() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Package> >
 PackageImpl::getNestedPackages() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Stereotype> >
 PackageImpl::getOwnedStereotypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Type> >
 PackageImpl::getOwnedTypes() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ProfileApplication> 
 PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile>  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::ProfileApplication> 
 PackageImpl::getProfileApplication(std::shared_ptr<uml::Profile>  profile,bool recurse) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PackageImpl::isModelLibrary() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PackageImpl::isProfileApplied(std::shared_ptr<uml::Profile>  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 PackageImpl::makesVisible(std::shared_ptr<uml::NamedElement>  el) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<ecore::EObject> >
 PackageImpl::unapplyProfile(std::shared_ptr<uml::Profile>  profile) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::PackageableElement> >
 PackageImpl::visibleMembers() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::Package, uml::PackageableElement /*Subset does not reference a union*/ > >
 PackageImpl::getNestedPackage() const
{

    return m_nestedPackage;
}


std::shared_ptr<uml::Package > PackageImpl::getNestingPackage() const
{

    return m_nestingPackage;
}
void PackageImpl::setNestingPackage(std::shared_ptr<uml::Package> _nestingPackage)
{
    m_nestingPackage = _nestingPackage;
}

		std::shared_ptr<Subset<uml::Stereotype, uml::PackageableElement /*Subset does not reference a union*/ > >
 PackageImpl::getOwnedStereotype() const
{

    return m_ownedStereotype;
}


		std::shared_ptr<Subset<uml::Type, uml::PackageableElement /*Subset does not reference a union*/ > >
 PackageImpl::getOwnedType() const
{

    return m_ownedType;
}


		std::shared_ptr<Subset<uml::PackageMerge, uml::Element > >
 PackageImpl::getPackageMerge() const
{

    return m_packageMerge;
}


		std::shared_ptr<SubsetUnion<uml::PackageableElement, uml::NamedElement > >
 PackageImpl::getPackagedElement() const
{

    return m_packagedElement;
}


		std::shared_ptr<Subset<uml::ProfileApplication, uml::Element > >
 PackageImpl::getProfileApplication() const
{

    return m_profileApplication;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > PackageImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > PackageImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > PackageImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 PackageImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::NamedElement> > PackageImpl::getMember() const
{
	

	return m_member;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any PackageImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //1320
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //134
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //130
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //1311
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //1314
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //1315
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //135
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //136
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //137
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //1321
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //1322
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //131
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //132
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //1313
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //1310
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //1323
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //135
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //1324
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //133
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //134
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //1312
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //1325
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //1326
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //1327
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //138
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //134
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //135
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //139
	}
	return boost::any();
}
