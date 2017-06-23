#include "InformationItemImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InformationItemImpl::InformationItemImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		m_represented.reset(new Bag<uml::Classifier>());
	
	
}

InformationItemImpl::~InformationItemImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete InformationItem "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InformationItemImpl::InformationItemImpl(const InformationItemImpl & obj)
{
	//create copy of all Attributes
	m_isAbstract = obj.getIsAbstract();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_name = obj.getName();
	m_qualifiedName = obj.getQualifiedName();
	m_visibility = obj.getVisibility();

	//copy references with now containment
	
			std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
	 _attribute = obj.getAttribute();
	m_attribute.reset(new 		SubsetUnion<uml::Property, uml::Feature > 
	(*(obj.getAttribute().get())));// this->getAttribute()->insert(this->getAttribute()->end(), _attribute->begin(), _attribute->end());

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

			std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
	 _feature = obj.getFeature();
	m_feature.reset(new 		SubsetUnion<uml::Feature, uml::NamedElement > 
	(*(obj.getFeature().get())));// this->getFeature()->insert(this->getFeature()->end(), _feature->begin(), _feature->end());

		std::shared_ptr< Bag<uml::Classifier> >
	 _general = obj.getGeneral();
	m_general.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getGeneral().get())));// this->getGeneral()->insert(this->getGeneral()->end(), _general->begin(), _general->end());

			std::shared_ptr<Subset<uml::PackageableElement, uml::NamedElement > >
	 _importedMember = obj.getImportedMember();
	m_importedMember.reset(new 		Subset<uml::PackageableElement, uml::NamedElement > 
	(*(obj.getImportedMember().get())));// this->getImportedMember()->insert(this->getImportedMember()->end(), _importedMember->begin(), _importedMember->end());

			std::shared_ptr<Subset<uml::NamedElement, uml::NamedElement > >
	 _inheritedMember = obj.getInheritedMember();
	m_inheritedMember.reset(new 		Subset<uml::NamedElement, uml::NamedElement > 
	(*(obj.getInheritedMember().get())));// this->getInheritedMember()->insert(this->getInheritedMember()->end(), _inheritedMember->begin(), _inheritedMember->end());

			std::shared_ptr<Union<uml::NamedElement> > _member = obj.getMember();
	m_member.reset(new 		Union<uml::NamedElement> (*(obj.getMember().get())));// this->getMember()->insert(this->getMember()->end(), _member->begin(), _member->end());

	m_namespace  = obj.getNamespace();

			std::shared_ptr<Union<uml::Element> > _ownedElement = obj.getOwnedElement();
	m_ownedElement.reset(new 		Union<uml::Element> (*(obj.getOwnedElement().get())));// this->getOwnedElement()->insert(this->getOwnedElement()->end(), _ownedElement->begin(), _ownedElement->end());

			std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > >
	 _ownedMember = obj.getOwnedMember();
	m_ownedMember.reset(new 		SubsetUnion<uml::NamedElement, uml::Element
			,uml::NamedElement > 
	(*(obj.getOwnedMember().get())));// this->getOwnedMember()->insert(this->getOwnedMember()->end(), _ownedMember->begin(), _ownedMember->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

		std::shared_ptr< Bag<uml::GeneralizationSet> >
	 _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new 	 Bag<uml::GeneralizationSet> 
	(*(obj.getPowertypeExtent().get())));// this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > >
	 _redefinedClassifier = obj.getRedefinedClassifier();
	m_redefinedClassifier.reset(new 		SubsetUnion<uml::Classifier, uml::RedefinableElement > 
	(*(obj.getRedefinedClassifier().get())));// this->getRedefinedClassifier()->insert(this->getRedefinedClassifier()->end(), _redefinedClassifier->begin(), _redefinedClassifier->end());

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_representation  = obj.getRepresentation();

		std::shared_ptr< Bag<uml::Classifier> >
	 _represented = obj.getRepresented();
	m_represented.reset(new 	 Bag<uml::Classifier> 
	(*(obj.getRepresented().get())));// this->getRepresented()->insert(this->getRepresented()->end(), _represented->begin(), _represented->end());

	m_templateParameter  = obj.getTemplateParameter();

		std::shared_ptr< Bag<uml::UseCase> >
	 _useCase = obj.getUseCase();
	m_useCase.reset(new 	 Bag<uml::UseCase> 
	(*(obj.getUseCase().get())));// this->getUseCase()->insert(this->getUseCase()->end(), _useCase->begin(), _useCase->end());


	//clone containt lists
	std::shared_ptr<Bag<uml::CollaborationUse>> _collaborationUseList = obj.getCollaborationUse();
	for(std::shared_ptr<uml::CollaborationUse> _collaborationUse : *_collaborationUseList)
	{
		this->getCollaborationUse()->add(std::shared_ptr<uml::CollaborationUse>(dynamic_cast<uml::CollaborationUse*>(_collaborationUse->copy())));
	}
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
	std::shared_ptr<Bag<uml::Generalization>> _generalizationList = obj.getGeneralization();
	for(std::shared_ptr<uml::Generalization> _generalization : *_generalizationList)
	{
		this->getGeneralization()->add(std::shared_ptr<uml::Generalization>(dynamic_cast<uml::Generalization*>(_generalization->copy())));
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
	std::shared_ptr<Bag<uml::UseCase>> _ownedUseCaseList = obj.getOwnedUseCase();
	for(std::shared_ptr<uml::UseCase> _ownedUseCase : *_ownedUseCaseList)
	{
		this->getOwnedUseCase()->add(std::shared_ptr<uml::UseCase>(dynamic_cast<uml::UseCase*>(_ownedUseCase->copy())));
	}
	std::shared_ptr<Bag<uml::PackageImport>> _packageImportList = obj.getPackageImport();
	for(std::shared_ptr<uml::PackageImport> _packageImport : *_packageImportList)
	{
		this->getPackageImport()->add(std::shared_ptr<uml::PackageImport>(dynamic_cast<uml::PackageImport*>(_packageImport->copy())));
	}
	std::shared_ptr<Bag<uml::Substitution>> _substitutionList = obj.getSubstitution();
	for(std::shared_ptr<uml::Substitution> _substitution : *_substitutionList)
	{
		this->getSubstitution()->add(std::shared_ptr<uml::Substitution>(dynamic_cast<uml::Substitution*>(_substitution->copy())));
	}
	std::shared_ptr<Bag<uml::TemplateBinding>> _templateBindingList = obj.getTemplateBinding();
	for(std::shared_ptr<uml::TemplateBinding> _templateBinding : *_templateBindingList)
	{
		this->getTemplateBinding()->add(std::shared_ptr<uml::TemplateBinding>(dynamic_cast<uml::TemplateBinding*>(_templateBinding->copy())));
	}
}

ecore::EObject *  InformationItemImpl::copy() const
{
	return new InformationItemImpl(*this);
}

std::shared_ptr<ecore::EClass> InformationItemImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInformationItem();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 InformationItemImpl::has_no(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InformationItemImpl::not_instantiable(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InformationItemImpl::sources_and_targets(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
	std::shared_ptr< Bag<uml::Classifier> >
 InformationItemImpl::getRepresented() const
{

    return m_represented;
}


//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Namespace > InformationItemImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::NamedElement> > InformationItemImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<Union<uml::Element> > InformationItemImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 InformationItemImpl::getFeature() const
{
	

	return m_feature;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 InformationItemImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::RedefinableElement> > InformationItemImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
std::shared_ptr<uml::Element > InformationItemImpl::getOwner() const
{
	

	return m_owner;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InformationItemImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //22425
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //2244
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //22426
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //2240
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //22411
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //22424
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //22427
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //22428
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //22414
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //22430
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //22431
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //22432
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //22410
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //22415
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //2245
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //2246
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //2247
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //2241
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //2242
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //22413
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //22410
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //2245
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //22433
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //2243
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //2244
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //22412
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //22412
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //22429
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //2248
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //22435
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //22411
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //22412
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //22436
		case UmlPackage::INFORMATIONITEM_REPRESENTED:
			return getRepresented(); //22438
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //22437
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //2244
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //2245
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //22434
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //2249
	}
	return boost::any();
}
