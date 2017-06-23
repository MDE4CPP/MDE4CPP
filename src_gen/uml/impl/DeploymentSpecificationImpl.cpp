#include "DeploymentSpecificationImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
DeploymentSpecificationImpl::DeploymentSpecificationImpl()
{
	//*********************************
	// Attribute Members
	//*********************************
	
	
	//*********************************
	// Reference Members
	//*********************************
	
}

DeploymentSpecificationImpl::~DeploymentSpecificationImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete DeploymentSpecification "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

DeploymentSpecificationImpl::DeploymentSpecificationImpl(const DeploymentSpecificationImpl & obj)
{
	//create copy of all Attributes
	m_deploymentLocation = obj.getDeploymentLocation();
	m_executionLocation = obj.getExecutionLocation();
	m_fileName = obj.getFileName();
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

	m_deployment  = obj.getDeployment();

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
	std::shared_ptr<Bag<uml::Manifestation>> _manifestationList = obj.getManifestation();
	for(std::shared_ptr<uml::Manifestation> _manifestation : *_manifestationList)
	{
		this->getManifestation()->add(std::shared_ptr<uml::Manifestation>(dynamic_cast<uml::Manifestation*>(_manifestation->copy())));
	}
	if(obj.getNameExpression()!=nullptr)
	{
		m_nameExpression.reset(dynamic_cast<uml::StringExpression*>(obj.getNameExpression()->copy()));
	}
	std::shared_ptr<Bag<uml::Artifact>> _nestedArtifactList = obj.getNestedArtifact();
	for(std::shared_ptr<uml::Artifact> _nestedArtifact : *_nestedArtifactList)
	{
		this->getNestedArtifact()->add(std::shared_ptr<uml::Artifact>(dynamic_cast<uml::Artifact*>(_nestedArtifact->copy())));
	}
	std::shared_ptr<Bag<uml::Property>> _ownedAttributeList = obj.getOwnedAttribute();
	for(std::shared_ptr<uml::Property> _ownedAttribute : *_ownedAttributeList)
	{
		this->getOwnedAttribute()->add(std::shared_ptr<uml::Property>(dynamic_cast<uml::Property*>(_ownedAttribute->copy())));
	}
	std::shared_ptr<Bag<uml::Comment>> _ownedCommentList = obj.getOwnedComment();
	for(std::shared_ptr<uml::Comment> _ownedComment : *_ownedCommentList)
	{
		this->getOwnedComment()->add(std::shared_ptr<uml::Comment>(dynamic_cast<uml::Comment*>(_ownedComment->copy())));
	}
	std::shared_ptr<Bag<uml::Operation>> _ownedOperationList = obj.getOwnedOperation();
	for(std::shared_ptr<uml::Operation> _ownedOperation : *_ownedOperationList)
	{
		this->getOwnedOperation()->add(std::shared_ptr<uml::Operation>(dynamic_cast<uml::Operation*>(_ownedOperation->copy())));
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

ecore::EObject *  DeploymentSpecificationImpl::copy() const
{
	return new DeploymentSpecificationImpl(*this);
}

std::shared_ptr<ecore::EClass> DeploymentSpecificationImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getDeploymentSpecification();
}

//*********************************
// Attribute Setter Gettter
//*********************************
void DeploymentSpecificationImpl::setDeploymentLocation (std::string _deploymentLocation)
{
	m_deploymentLocation = _deploymentLocation;
} 

std::string DeploymentSpecificationImpl::getDeploymentLocation() const 
{
	return m_deploymentLocation;
}

void DeploymentSpecificationImpl::setExecutionLocation (std::string _executionLocation)
{
	m_executionLocation = _executionLocation;
} 

std::string DeploymentSpecificationImpl::getExecutionLocation() const 
{
	return m_executionLocation;
}

//*********************************
// Operations
//*********************************
bool
 DeploymentSpecificationImpl::deployed_elements(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 DeploymentSpecificationImpl::deployment_target(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
std::shared_ptr<uml::Deployment > DeploymentSpecificationImpl::getDeployment() const
{

    return m_deployment;
}
void DeploymentSpecificationImpl::setDeployment(std::shared_ptr<uml::Deployment> _deployment)
{
    m_deployment = _deployment;
}

//*********************************
// Union Getter
//*********************************
std::shared_ptr<uml::Element > DeploymentSpecificationImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::Element> > DeploymentSpecificationImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Namespace > DeploymentSpecificationImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<Union<uml::NamedElement> > DeploymentSpecificationImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 DeploymentSpecificationImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::RedefinableElement> > DeploymentSpecificationImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
 DeploymentSpecificationImpl::getAttribute() const
{
	

	return m_attribute;
}
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 DeploymentSpecificationImpl::getFeature() const
{
	

	return m_feature;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any DeploymentSpecificationImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //3825
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //384
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //3826
		case UmlPackage::DEPLOYMENTSPECIFICATION_DEPLOYMENT:
			return getDeployment(); //3845
		case UmlPackage::DEPLOYMENTSPECIFICATION_DEPLOYMENTLOCATION:
			return getDeploymentLocation(); //3843
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //380
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //3811
		case UmlPackage::DEPLOYMENTSPECIFICATION_EXECUTIONLOCATION:
			return getExecutionLocation(); //3844
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //3824
		case UmlPackage::ARTIFACT_FILENAME:
			return getFileName(); //3838
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //3827
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //3828
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //3814
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //3830
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //3831
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //3832
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //3810
		case UmlPackage::ARTIFACT_MANIFESTATION:
			return getManifestation(); //3839
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //3815
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //385
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //386
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //387
		case UmlPackage::ARTIFACT_NESTEDARTIFACT:
			return getNestedArtifact(); //3840
		case UmlPackage::ARTIFACT_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //3841
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //381
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //382
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //3813
		case UmlPackage::ARTIFACT_OWNEDOPERATION:
			return getOwnedOperation(); //3842
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //3810
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //385
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //3833
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //383
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //384
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //3812
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //3812
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //3829
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //388
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //3835
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //3811
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //3812
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //3836
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //3837
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //384
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //385
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //3834
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //389
	}
	return boost::any();
}
