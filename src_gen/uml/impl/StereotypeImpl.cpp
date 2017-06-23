#include "StereotypeImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
StereotypeImpl::StereotypeImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Subset*/
		m_icon.reset(new Subset<uml::Image, uml::Element >(m_ownedElement));//(m_ownedElement));
	
	
	
}

StereotypeImpl::~StereotypeImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Stereotype "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

StereotypeImpl::StereotypeImpl(const StereotypeImpl & obj)
{
	//create copy of all Attributes
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
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

	m_classifierBehavior  = obj.getClassifierBehavior();

		std::shared_ptr< Bag<uml::Dependency> >
	 _clientDependency = obj.getClientDependency();
	m_clientDependency.reset(new 	 Bag<uml::Dependency> 
	(*(obj.getClientDependency().get())));// this->getClientDependency()->insert(this->getClientDependency()->end(), _clientDependency->begin(), _clientDependency->end());

		std::shared_ptr< Bag<uml::Extension> >
	 _extension = obj.getExtension();
	m_extension.reset(new 	 Bag<uml::Extension> 
	(*(obj.getExtension().get())));// this->getExtension()->insert(this->getExtension()->end(), _extension->begin(), _extension->end());

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

			std::shared_ptr<Subset<uml::Port, uml::Property /*Subset does not reference a union*/ > >
	 _ownedPort = obj.getOwnedPort();
	m_ownedPort.reset(new 		Subset<uml::Port, uml::Property /*Subset does not reference a union*/ > 
	(*(obj.getOwnedPort().get())));// this->getOwnedPort()->insert(this->getOwnedPort()->end(), _ownedPort->begin(), _ownedPort->end());

	m_owner  = obj.getOwner();

	m_owningTemplateParameter  = obj.getOwningTemplateParameter();

	m_package  = obj.getPackage();

		std::shared_ptr< Bag<uml::Property> >
	 _part = obj.getPart();
	m_part.reset(new 	 Bag<uml::Property> 
	(*(obj.getPart().get())));// this->getPart()->insert(this->getPart()->end(), _part->begin(), _part->end());

		std::shared_ptr< Bag<uml::GeneralizationSet> >
	 _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new 	 Bag<uml::GeneralizationSet> 
	(*(obj.getPowertypeExtent().get())));// this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

	m_profile  = obj.getProfile();

			std::shared_ptr<SubsetUnion<uml::Classifier, uml::RedefinableElement > >
	 _redefinedClassifier = obj.getRedefinedClassifier();
	m_redefinedClassifier.reset(new 		SubsetUnion<uml::Classifier, uml::RedefinableElement > 
	(*(obj.getRedefinedClassifier().get())));// this->getRedefinedClassifier()->insert(this->getRedefinedClassifier()->end(), _redefinedClassifier->begin(), _redefinedClassifier->end());

			std::shared_ptr<Union<uml::RedefinableElement> > _redefinedElement = obj.getRedefinedElement();
	m_redefinedElement.reset(new 		Union<uml::RedefinableElement> (*(obj.getRedefinedElement().get())));// this->getRedefinedElement()->insert(this->getRedefinedElement()->end(), _redefinedElement->begin(), _redefinedElement->end());

			std::shared_ptr<Union<uml::Classifier> > _redefinitionContext = obj.getRedefinitionContext();
	m_redefinitionContext.reset(new 		Union<uml::Classifier> (*(obj.getRedefinitionContext().get())));// this->getRedefinitionContext()->insert(this->getRedefinitionContext()->end(), _redefinitionContext->begin(), _redefinitionContext->end());

	m_representation  = obj.getRepresentation();

			std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > >
	 _role = obj.getRole();
	m_role.reset(new 		SubsetUnion<uml::ConnectableElement, uml::NamedElement > 
	(*(obj.getRole().get())));// this->getRole()->insert(this->getRole()->end(), _role->begin(), _role->end());

		std::shared_ptr< Bag<uml::Class> >
	 _superClass = obj.getSuperClass();
	m_superClass.reset(new 	 Bag<uml::Class> 
	(*(obj.getSuperClass().get())));// this->getSuperClass()->insert(this->getSuperClass()->end(), _superClass->begin(), _superClass->end());

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
	std::shared_ptr<Bag<uml::Image>> _iconList = obj.getIcon();
	for(std::shared_ptr<uml::Image> _icon : *_iconList)
	{
		this->getIcon()->add(std::shared_ptr<uml::Image>(dynamic_cast<uml::Image*>(_icon->copy())));
	}
	std::shared_ptr<Bag<uml::InterfaceRealization>> _interfaceRealizationList = obj.getInterfaceRealization();
	for(std::shared_ptr<uml::InterfaceRealization> _interfaceRealization : *_interfaceRealizationList)
	{
		this->getInterfaceRealization()->add(std::shared_ptr<uml::InterfaceRealization>(dynamic_cast<uml::InterfaceRealization*>(_interfaceRealization->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Classifier>> _nestedClassifierList = obj.getNestedClassifier();
	for(std::shared_ptr<uml::Classifier> _nestedClassifier : *_nestedClassifierList)
	{
		this->getNestedClassifier()->add(std::shared_ptr<uml::Classifier>(dynamic_cast<uml::Classifier*>(_nestedClassifier->copy())));
	}
	std::shared_ptr<Bag<uml::Property>> _ownedAttributeList = obj.getOwnedAttribute();
	for(std::shared_ptr<uml::Property> _ownedAttribute : *_ownedAttributeList)
	{
		this->getOwnedAttribute()->add(std::shared_ptr<uml::Property>(dynamic_cast<uml::Property*>(_ownedAttribute->copy())));
	}
	std::shared_ptr<Bag<uml::Behavior>> _ownedBehaviorList = obj.getOwnedBehavior();
	for(std::shared_ptr<uml::Behavior> _ownedBehavior : *_ownedBehaviorList)
	{
		this->getOwnedBehavior()->add(std::shared_ptr<uml::Behavior>(dynamic_cast<uml::Behavior*>(_ownedBehavior->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Connector>> _ownedConnectorList = obj.getOwnedConnector();
	for(std::shared_ptr<uml::Connector> _ownedConnector : *_ownedConnectorList)
	{
		this->getOwnedConnector()->add(std::shared_ptr<uml::Connector>(dynamic_cast<uml::Connector*>(_ownedConnector->copy())));
	}
	std::shared_ptr<Bag<uml::Operation>> _ownedOperationList = obj.getOwnedOperation();
	for(std::shared_ptr<uml::Operation> _ownedOperation : *_ownedOperationList)
	{
		this->getOwnedOperation()->add(std::shared_ptr<uml::Operation>(dynamic_cast<uml::Operation*>(_ownedOperation->copy())));
	}
	std::shared_ptr<Bag<uml::Reception>> _ownedReceptionList = obj.getOwnedReception();
	for(std::shared_ptr<uml::Reception> _ownedReception : *_ownedReceptionList)
	{
		this->getOwnedReception()->add(std::shared_ptr<uml::Reception>(dynamic_cast<uml::Reception*>(_ownedReception->copy())));
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

ecore::EObject *  StereotypeImpl::copy() const
{
	return new StereotypeImpl(*this);
}

std::shared_ptr<ecore::EClass> StereotypeImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getStereotype();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 StereotypeImpl::associationEndOwnership(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StereotypeImpl::base_property_multiplicity_multiple_extension(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StereotypeImpl::base_property_multiplicity_single_extension(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StereotypeImpl::base_property_upper_bound(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StereotypeImpl::binaryAssociationsOnly(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Profile> 
 StereotypeImpl::containingProfile() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Extension> 
 StereotypeImpl::createExtension(std::shared_ptr<uml::Class>  metaclass,bool isRequired) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Image> 
 StereotypeImpl::createIcon(std::string location) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Image> 
 StereotypeImpl::createIcon(std::string format,std::string content) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 StereotypeImpl::generalize(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> >
 StereotypeImpl::getAllExtendedMetaclasses() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<ecore::EClass> 
 StereotypeImpl::getDefinition() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<Bag<uml::Class> >
 StereotypeImpl::getExtendedMetaclasses() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string
 StereotypeImpl::getKeyword() 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::string
 StereotypeImpl::getKeyword(bool localize) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}



bool
 StereotypeImpl::name_not_clash(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::Image, uml::Element > >
 StereotypeImpl::getIcon() const
{

    return m_icon;
}


std::shared_ptr<uml::Profile > StereotypeImpl::getProfile() const
{
//assert(m_profile);
    return m_profile;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 StereotypeImpl::getFeature() const
{
	

	return m_feature;
}
		std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > >
 StereotypeImpl::getRole() const
{
	

	return m_role;
}
std::shared_ptr<uml::Namespace > StereotypeImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
 StereotypeImpl::getAttribute() const
{
	

	return m_attribute;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 StereotypeImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
std::shared_ptr<uml::Element > StereotypeImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > StereotypeImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<Union<uml::Element> > StereotypeImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<Union<uml::NamedElement> > StereotypeImpl::getMember() const
{
	

	return m_member;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any StereotypeImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //1025
		case UmlPackage::BEHAVIOREDCLASSIFIER_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //1038
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //104
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //1026
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //100
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //1011
		case UmlPackage::CLASS_EXTENSION:
			return getExtension(); //1047
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //1024
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //1027
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //1028
		case UmlPackage::STEREOTYPE_ICON:
			return getIcon(); //1052
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //1014
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //1030
		case UmlPackage::BEHAVIOREDCLASSIFIER_INTERFACEREALIZATION:
			return getInterfaceRealization(); //1039
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //1031
		case UmlPackage::CLASS_ISACTIVE:
			return getIsActive(); //1048
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //1032
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //1010
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //1015
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //105
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //106
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //107
		case UmlPackage::CLASS_NESTEDCLASSIFIER:
			return getNestedClassifier(); //1049
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //1038
		case UmlPackage::BEHAVIOREDCLASSIFIER_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //1040
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //101
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDCONNECTOR:
			return getOwnedConnector(); //1039
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //102
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //1013
		case UmlPackage::CLASS_OWNEDOPERATION:
			return getOwnedOperation(); //1046
		case UmlPackage::ENCAPSULATEDCLASSIFIER_OWNEDPORT:
			return getOwnedPort(); //1042
		case UmlPackage::CLASS_OWNEDRECEPTION:
			return getOwnedReception(); //1050
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //1010
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //105
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //1033
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //103
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //104
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //1012
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //1012
		case UmlPackage::STRUCTUREDCLASSIFIER_PART:
			return getPart(); //1040
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //1029
		case UmlPackage::STEREOTYPE_PROFILE:
			return getProfile(); //1053
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //108
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //1035
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //1011
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //1012
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //1036
		case UmlPackage::STRUCTUREDCLASSIFIER_ROLE:
			return getRole(); //1041
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //1037
		case UmlPackage::CLASS_SUPERCLASS:
			return getSuperClass(); //1051
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //104
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //105
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //1034
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //109
	}
	return boost::any();
}
