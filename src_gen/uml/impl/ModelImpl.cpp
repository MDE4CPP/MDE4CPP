#include "ModelImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
ModelImpl::ModelImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	//*********************************
	// Reference Members
	//*********************************

}

ModelImpl::~ModelImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Model "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

ModelImpl::ModelImpl(const ModelImpl & obj)
{
	//create copy of all Attributes
	m_URI = obj.getURI();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_viewpoint = obj.getViewpoint();
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

ecore::EObject *  ModelImpl::copy() const
{
	return new ModelImpl(*this);
}

std::shared_ptr<ecore::EClass> ModelImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getModel();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void ModelImpl::setViewpoint (std::string _viewpoint)
{
	m_viewpoint = _viewpoint;
} 

std::string ModelImpl::getViewpoint() const 
{
	return m_viewpoint;
}

//*********************************
// Operations
//*********************************
bool
 ModelImpl::isMetamodel() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************

//*********************************
// Union Getter
//*********************************
		std::shared_ptr<Union<uml::Element> > ModelImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::NamedElement> > ModelImpl::getMember() const
{
	

	return m_member;
}
std::shared_ptr<uml::Namespace > ModelImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > ModelImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 ModelImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any ModelImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::PACKAGE_URI:
			return getURI(); //8620
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //864
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //860
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //8611
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //8614
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //8615
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //865
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //866
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //867
		case UmlPackage::PACKAGE_NESTEDPACKAGE:
			return getNestedPackage(); //8621
		case UmlPackage::PACKAGE_NESTINGPACKAGE:
			return getNestingPackage(); //8622
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //861
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //862
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //8613
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //8610
		case UmlPackage::PACKAGE_OWNEDSTEREOTYPE:
			return getOwnedStereotype(); //8623
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //865
		case UmlPackage::PACKAGE_OWNEDTYPE:
			return getOwnedType(); //8624
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //863
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //864
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //8612
		case UmlPackage::PACKAGE_PACKAGEMERGE:
			return getPackageMerge(); //8625
		case UmlPackage::PACKAGE_PACKAGEDELEMENT:
			return getPackagedElement(); //8626
		case UmlPackage::PACKAGE_PROFILEAPPLICATION:
			return getProfileApplication(); //8627
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //868
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //864
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //865
		case UmlPackage::MODEL_VIEWPOINT:
			return getViewpoint(); //8628
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //869
	}
	return boost::any();
}
