#include "ProfileImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "UmlPackageImpl.hpp"

//Forward declaration includes
#include "Class.hpp"

#include "Classifier.hpp"

#include "Comment.hpp"

#include "Constraint.hpp"

#include "Dependency.hpp"

#include "EAnnotation.hpp"

#include "ENamedElement.hpp"

#include "EObject.hpp"

#include "EPackage.hpp"

#include "Element.hpp"

#include "ElementImport.hpp"

#include "Extension.hpp"

#include "Model.hpp"

#include "NamedElement.hpp"

#include "Namespace.hpp"

#include "Package.hpp"

#include "PackageImport.hpp"

#include "PackageMerge.hpp"

#include "PackageableElement.hpp"

#include "ProfileApplication.hpp"

#include "Stereotype.hpp"

#include "StringExpression.hpp"

#include "TemplateBinding.hpp"

#include "TemplateParameter.hpp"

#include "TemplateSignature.hpp"

#include "Type.hpp"


using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ProfileImpl::ProfileImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
	//References
		/*Subset*/
		m_metaclassReference.reset(new Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

		/*Subset*/
		m_metamodelReference.reset(new Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >());
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising shared pointer Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >()" << std::endl;
		#endif
	
	

	//Init references
		/*Subset*/
		m_metaclassReference->initSubset(m_elementImport);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metaclassReference - Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ >(m_elementImport)" << std::endl;
		#endif
	
	

		/*Subset*/
		m_metamodelReference->initSubset(m_packageImport);
		#ifdef SHOW_SUBSET_UNION
			std::cout << "Initialising value Subset: " << "m_metamodelReference - Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ >(m_packageImport)" << std::endl;
		#endif
	
	
}

ProfileImpl::~ProfileImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Profile "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}


//Additional constructor for the containments back reference
			ProfileImpl::ProfileImpl(std::shared_ptr<uml::Package > par_nestingPackage)
			:ProfileImpl()
			{
			    m_nestingPackage = par_nestingPackage;
			}






ProfileImpl::ProfileImpl(const ProfileImpl & obj):ProfileImpl()
{
	//create copy of all Attributes
	#ifdef SHOW_COPIES
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\r\ncopy Profile "<< this << "\r\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
	#endif
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with no containment (soft copy)
	
	std::shared_ptr< Bag<uml::Dependency> > _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new Bag<uml::Dependency>(*(obj.getClientDependency().get())));

	std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new Union<uml::NamedElement>(*(obj.getMember().get())));

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_templateParameter  = obj.getTemplateParameter();


    
	//Clone references with containment (deep copy)

	std::shared_ptr<Bag<ecore::EAnnotation>> _eAnnotationsList = obj.getEAnnotations();
	for(std::shared_ptr<ecore::EAnnotation> _eAnnotations : *_eAnnotationsList)
	{
		this->getEAnnotations()->add(std::shared_ptr<ecore::EAnnotation>(dynamic_cast<ecore::EAnnotation*>(_eAnnotations->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_eAnnotations" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _elementImportList = obj.getElementImport();
	for(std::shared_ptr<uml::ElementImport> _elementImport : *_elementImportList)
	{
		this->getElementImport()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_elementImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_elementImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _importedMemberList = obj.getImportedMember();
	for(std::shared_ptr<uml::PackageableElement> _importedMember : *_importedMemberList)
	{
		this->getImportedMember()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_importedMember->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_importedMember" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ElementImport>> _metaclassReferenceList = obj.getMetaclassReference();
	for(std::shared_ptr<uml::ElementImport> _metaclassReference : *_metaclassReferenceList)
	{
		this->getMetaclassReference()->add(std::shared_ptr<uml::ElementImport>(dynamic_cast<uml::ElementImport*>(_metaclassReference->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_metaclassReference" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _metamodelReferenceList = obj.getMetamodelReference();
	for(std::shared_ptr<uml::PackageImport> _metamodelReference : *_metamodelReferenceList)
	{
		this->getMetamodelReference()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_metamodelReference->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_metamodelReference" << std::endl;
	#endif
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nameExpression" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Package>> _nestedPackageList = obj.getNestedPackage();
	for(std::shared_ptr<uml::Package> _nestedPackage : *_nestedPackageList)
	{
		this->getNestedPackage()->add(std::shared_ptr<uml::Package>(dynamic_cast<uml::Package*>(_nestedPackage->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nestedPackage" << std::endl;
	#endif
	if(obj.getNestingPackage()!=nullptr)
	{
		m_nestingPackage.reset(dynamic_cast<uml::Package*>(obj.getNestingPackage()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_nestingPackage" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedComment" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Constraint>> _ownedRuleList = obj.getOwnedRule();
	for(std::shared_ptr<uml::Constraint> _ownedRule : *_ownedRuleList)
	{
		this->getOwnedRule()->add(std::shared_ptr<uml::Constraint>(dynamic_cast<uml::Constraint*>(_ownedRule->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedRule" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Stereotype>> _ownedStereotypeList = obj.getOwnedStereotype();
	for(std::shared_ptr<uml::Stereotype> _ownedStereotype : *_ownedStereotypeList)
	{
		this->getOwnedStereotype()->add(std::shared_ptr<uml::Stereotype>(dynamic_cast<uml::Stereotype*>(_ownedStereotype->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedStereotype" << std::endl;
	#endif
	if(obj.getOwnedTemplateSignature()!=nullptr)
	{
		m_ownedTemplateSignature.reset(dynamic_cast<uml::TemplateSignature*>(obj.getOwnedTemplateSignature()->copy()));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedTemplateSignature" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::Type>> _ownedTypeList = obj.getOwnedType();
	for(std::shared_ptr<uml::Type> _ownedType : *_ownedTypeList)
	{
		this->getOwnedType()->add(std::shared_ptr<uml::Type>(dynamic_cast<uml::Type*>(_ownedType->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_ownedType" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageImport" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageMerge>> _packageMergeList = obj.getPackageMerge();
	for(std::shared_ptr<uml::PackageMerge> _packageMerge : *_packageMergeList)
	{
		this->getPackageMerge()->add(std::shared_ptr<uml::PackageMerge>(dynamic_cast<uml::PackageMerge*>(_packageMerge->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packageMerge" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::PackageableElement>> _packagedElementList = obj.getPackagedElement();
	for(std::shared_ptr<uml::PackageableElement> _packagedElement : *_packagedElementList)
	{
		this->getPackagedElement()->add(std::shared_ptr<uml::PackageableElement>(dynamic_cast<uml::PackageableElement*>(_packagedElement->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_packagedElement" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::ProfileApplication>> _profileApplicationList = obj.getProfileApplication();
	for(std::shared_ptr<uml::ProfileApplication> _profileApplication : *_profileApplicationList)
	{
		this->getProfileApplication()->add(std::shared_ptr<uml::ProfileApplication>(dynamic_cast<uml::ProfileApplication*>(_profileApplication->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_profileApplication" << std::endl;
	#endif
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
	#ifdef SHOW_SUBSET_UNION
		std::cout << "Copying the Subset: " << "m_templateBinding" << std::endl;
	#endif


}

ecore::EObject *  ProfileImpl::copy() const
{
	return new ProfileImpl(*this);
}

std::shared_ptr<ecore::EClass> ProfileImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getProfile();
}

//*********************************
// Attribute Setter Getter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<ecore::EObject> ProfileImpl::create(std::shared_ptr<uml::Classifier>  classifier) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::define(std::map <   std::string, std::string >  options,boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EPackage> ProfileImpl::getDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::ENamedElement> ProfileImpl::getDefinition(std::shared_ptr<uml::NamedElement>  namedElement) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Extension> > ProfileImpl::getOwnedExtensions(bool requiredOnly) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> > ProfileImpl::getReferencedMetaclasses() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Model> > ProfileImpl::getReferencedMetamodels() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::isDefined() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::metaclass_reference_not_specialized(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool ProfileImpl::references_same_metamodel(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<Subset<uml::ElementImport, uml::ElementImport /*Subset does not reference a union*/ > > ProfileImpl::getMetaclassReference() const
{

    return m_metaclassReference;
}


std::shared_ptr<Subset<uml::PackageImport, uml::PackageImport /*Subset does not reference a union*/ > > ProfileImpl::getMetamodelReference() const
{

    return m_metamodelReference;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element,uml::NamedElement > > ProfileImpl::getOwnedMember() const
{
	return m_ownedMember;
}
std::shared_ptr<uml::Namespace > ProfileImpl::getNamespace() const
{
	return m_namespace;
}
std::shared_ptr<Union<uml::Element> > ProfileImpl::getOwnedElement() const
{
	return m_ownedElement;
}
std::weak_ptr<uml::Element > ProfileImpl::getOwner() const
{
	return m_owner;
}
std::shared_ptr<Union<uml::NamedElement> > ProfileImpl::getMember() const
{
	return m_member;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ProfileImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //1220
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //124
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //120
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //1211
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //1214
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //1215
		case UmlPackage::PROFILE_METACLASSREFERENCE:
			return getMetaclassReference(); //1228
		case UmlPackage::PROFILE_METAMODELREFERENCE:
			return getMetamodelReference(); //1229
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //125
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //126
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //127
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //1221
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //1222
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //121
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //122
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //1213
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //1210
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //1223
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //125
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //1224
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //123
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //124
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //1212
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //1225
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //1226
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //1227
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //128
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //124
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //125
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //129
	}
	return boost::any();
}
