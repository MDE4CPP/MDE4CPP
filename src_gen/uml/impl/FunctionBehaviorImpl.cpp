#include "FunctionBehaviorImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
FunctionBehaviorImpl::FunctionBehaviorImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************

}

FunctionBehaviorImpl::~FunctionBehaviorImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete FunctionBehavior "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

FunctionBehaviorImpl::FunctionBehaviorImpl(const FunctionBehaviorImpl & obj)
{
	//create copy of all Attributes
	m_body = obj.getBody();
	m_isAbstract = obj.getIsAbstract();
	m_isActive = obj.getIsActive();
	m_isFinalSpecialization = obj.getIsFinalSpecialization();
	m_isLeaf = obj.getIsLeaf();
	m_isReentrant = obj.getIsReentrant();
	m_language = obj.getLanguage();
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

	m_context  = obj.getContext();

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

			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > >
	 _postcondition = obj.getPostcondition();
	m_postcondition.reset(new 		Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > 
	(*(obj.getPostcondition().get())));// this->getPostcondition()->insert(this->getPostcondition()->end(), _postcondition->begin(), _postcondition->end());

		std::shared_ptr< Bag<uml::GeneralizationSet> >
	 _powertypeExtent = obj.getPowertypeExtent();
	m_powertypeExtent.reset(new 	 Bag<uml::GeneralizationSet> 
	(*(obj.getPowertypeExtent().get())));// this->getPowertypeExtent()->insert(this->getPowertypeExtent()->end(), _powertypeExtent->begin(), _powertypeExtent->end());

			std::shared_ptr<Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > >
	 _precondition = obj.getPrecondition();
	m_precondition.reset(new 		Subset<uml::Constraint, uml::Constraint /*Subset does not reference a union*/ > 
	(*(obj.getPrecondition().get())));// this->getPrecondition()->insert(this->getPrecondition()->end(), _precondition->begin(), _precondition->end());

			std::shared_ptr<Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ > >
	 _redefinedBehavior = obj.getRedefinedBehavior();
	m_redefinedBehavior.reset(new 		Subset<uml::Behavior, uml::Classifier /*Subset does not reference a union*/ > 
	(*(obj.getRedefinedBehavior().get())));// this->getRedefinedBehavior()->insert(this->getRedefinedBehavior()->end(), _redefinedBehavior->begin(), _redefinedBehavior->end());

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

	m_specification  = obj.getSpecification();

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
	std::shared_ptr<Bag<uml::Parameter>> _ownedParameterList = obj.getOwnedParameter();
	for(std::shared_ptr<uml::Parameter> _ownedParameter : *_ownedParameterList)
	{
		this->getOwnedParameter()->add(std::shared_ptr<uml::Parameter>(dynamic_cast<uml::Parameter*>(_ownedParameter->copy())));
	}
	std::shared_ptr<Bag<uml::ParameterSet>> _ownedParameterSetList = obj.getOwnedParameterSet();
	for(std::shared_ptr<uml::ParameterSet> _ownedParameterSet : *_ownedParameterSetList)
	{
		this->getOwnedParameterSet()->add(std::shared_ptr<uml::ParameterSet>(dynamic_cast<uml::ParameterSet*>(_ownedParameterSet->copy())));
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

ecore::EObject *  FunctionBehaviorImpl::copy() const
{
	return new FunctionBehaviorImpl(*this);
}

std::shared_ptr<ecore::EClass> FunctionBehaviorImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getFunctionBehavior();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
bool
 FunctionBehaviorImpl::hasAllDataTypeAttributes(std::shared_ptr<uml::DataType>  d) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FunctionBehaviorImpl::one_output_parameter(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 FunctionBehaviorImpl::types_of_parameters(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
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
std::shared_ptr<uml::Namespace > FunctionBehaviorImpl::getNamespace() const
{
	

	return m_namespace;
}
		std::shared_ptr<SubsetUnion<uml::ConnectableElement, uml::NamedElement > >
 FunctionBehaviorImpl::getRole() const
{
	

	return m_role;
}
		std::shared_ptr<Union<uml::Classifier> > FunctionBehaviorImpl::getRedefinitionContext() const
{
	

	return m_redefinitionContext;
}
		std::shared_ptr<Union<uml::NamedElement> > FunctionBehaviorImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
 FunctionBehaviorImpl::getAttribute() const
{
	

	return m_attribute;
}
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 FunctionBehaviorImpl::getFeature() const
{
	

	return m_feature;
}
		std::shared_ptr<Union<uml::Element> > FunctionBehaviorImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
std::shared_ptr<uml::Element > FunctionBehaviorImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<Union<uml::RedefinableElement> > FunctionBehaviorImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 FunctionBehaviorImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any FunctionBehaviorImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //19925
		case UmlPackage::OPAQUEBEHAVIOR_BODY:
			return getBody(); //19960
		case UmlPackage::BEHAVIOREDCLASSIFIER_CLASSIFIERBEHAVIOR:
			return getClassifierBehavior(); //19938
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //1994
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //19926
		case UmlPackage::BEHAVIOR_CONTEXT:
			return getContext(); //19953
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //1990
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //19911
		case UmlPackage::CLASS_EXTENSION:
			return getExtension(); //19947
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //19924
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //19927
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //19928
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //19914
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //19930
		case UmlPackage::BEHAVIOREDCLASSIFIER_INTERFACEREALIZATION:
			return getInterfaceRealization(); //19939
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //19931
		case UmlPackage::CLASS_ISACTIVE:
			return getIsActive(); //19948
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //19932
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //19910
		case UmlPackage::BEHAVIOR_ISREENTRANT:
			return getIsReentrant(); //19954
		case UmlPackage::OPAQUEBEHAVIOR_LANGUAGE:
			return getLanguage(); //19961
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //19915
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //1995
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //1996
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //1997
		case UmlPackage::CLASS_NESTEDCLASSIFIER:
			return getNestedClassifier(); //19949
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //19938
		case UmlPackage::BEHAVIOREDCLASSIFIER_OWNEDBEHAVIOR:
			return getOwnedBehavior(); //19940
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //1991
		case UmlPackage::STRUCTUREDCLASSIFIER_OWNEDCONNECTOR:
			return getOwnedConnector(); //19939
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //1992
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //19913
		case UmlPackage::CLASS_OWNEDOPERATION:
			return getOwnedOperation(); //19946
		case UmlPackage::BEHAVIOR_OWNEDPARAMETER:
			return getOwnedParameter(); //19955
		case UmlPackage::BEHAVIOR_OWNEDPARAMETERSET:
			return getOwnedParameterSet(); //19956
		case UmlPackage::ENCAPSULATEDCLASSIFIER_OWNEDPORT:
			return getOwnedPort(); //19942
		case UmlPackage::CLASS_OWNEDRECEPTION:
			return getOwnedReception(); //19950
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //19910
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //1995
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //19933
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //1993
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //1994
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //19912
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //19912
		case UmlPackage::STRUCTUREDCLASSIFIER_PART:
			return getPart(); //19940
		case UmlPackage::BEHAVIOR_POSTCONDITION:
			return getPostcondition(); //19957
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //19929
		case UmlPackage::BEHAVIOR_PRECONDITION:
			return getPrecondition(); //19958
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //1998
		case UmlPackage::BEHAVIOR_REDEFINEDBEHAVIOR:
			return getRedefinedBehavior(); //19959
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //19935
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //19911
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //19912
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //19936
		case UmlPackage::STRUCTUREDCLASSIFIER_ROLE:
			return getRole(); //19941
		case UmlPackage::BEHAVIOR_SPECIFICATION:
			return getSpecification(); //19952
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //19937
		case UmlPackage::CLASS_SUPERCLASS:
			return getSuperClass(); //19951
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //1994
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //1995
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //19934
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //1999
	}
	return boost::any();
}
