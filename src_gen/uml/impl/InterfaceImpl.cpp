#include "InterfaceImpl.hpp"
#include <iostream>
#include <cassert>
#include "EAnnotation.hpp"
#include "EClass.hpp"
#include "umlPackageImpl.hpp"

using namespace uml;

//*********************************
// Constructor / Destructor
//*********************************
InterfaceImpl::InterfaceImpl()
{
	//*********************************
	// Attribute Members
	//*********************************

	//*********************************
	// Reference Members
	//*********************************
		/*Subset*/
		m_nestedClassifier.reset(new Subset<uml::Classifier, uml::NamedElement >(m_ownedMember));//(m_ownedMember));
	
	
		/*Subset*/
		m_ownedAttribute.reset(new Subset<uml::Property, uml::Property
		,uml::NamedElement >(m_attribute,m_ownedMember));//(m_attribute));
	
	
		/*Subset*/
		m_ownedOperation.reset(new Subset<uml::Operation, uml::Feature
		,uml::NamedElement >(m_feature,m_ownedMember));//(m_feature));
	
	
		/*Subset*/
		m_ownedReception.reset(new Subset<uml::Reception, uml::Feature
		,uml::NamedElement >(m_feature,m_ownedMember));//(m_feature));
	
	
	
		/*Subset*/
		m_redefinedInterface.reset(new Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ >(m_redefinedClassifier));//(m_redefinedClassifier));
	
	
}

InterfaceImpl::~InterfaceImpl()
{
#ifdef SHOW_DELETION
	std::cout << "-------------------------------------------------------------------------------------------------\r\ndelete Interface "<< this << "\r\n------------------------------------------------------------------------ " << std::endl;
#endif
	
}

InterfaceImpl::InterfaceImpl(const InterfaceImpl & obj)
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

			std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ > >
	 _redefinedInterface = obj.getRedefinedInterface();
	m_redefinedInterface.reset(new 		Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ > 
	(*(obj.getRedefinedInterface().get())));// this->getRedefinedInterface()->insert(this->getRedefinedInterface()->end(), _redefinedInterface->begin(), _redefinedInterface->end());

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
	if(obj.getProtocol()!=nullptr)
	{
		m_protocol.reset(dynamic_cast<uml::ProtocolStateMachine*>(obj.getProtocol()->copy()));
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

ecore::EObject *  InterfaceImpl::copy() const
{
	return new InterfaceImpl(*this);
}

std::shared_ptr<ecore::EClass> InterfaceImpl::eStaticClass() const
{
	return UmlPackageImpl::eInstance()->getInterface();
}

//*********************************
// Attribute Setter Gettter
//*********************************

//*********************************
// Operations
//*********************************
std::shared_ptr<uml::Property> 
 InterfaceImpl::createOwnedAttribute(std::string name,std::shared_ptr<uml::Type>  type,int lower,int upper) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

std::shared_ptr<uml::Operation> 
 InterfaceImpl::createOwnedOperation(std::string name,std::shared_ptr<Bag<std::string> >  parameterNames,std::shared_ptr<Bag<uml::Type> >  parameterTypes,std::shared_ptr<uml::Type>  returnType) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

bool
 InterfaceImpl::visibility(boost::any diagnostics,std::map <   boost::any, boost::any >  context) 
{
	std::cout << __PRETTY_FUNCTION__  << std::endl;
	throw "UnsupportedOperationException";
}

//*********************************
// References
//*********************************
		std::shared_ptr<Subset<uml::Classifier, uml::NamedElement > >
 InterfaceImpl::getNestedClassifier() const
{

    return m_nestedClassifier;
}


		std::shared_ptr<Subset<uml::Property, uml::Property
		,uml::NamedElement > >
 InterfaceImpl::getOwnedAttribute() const
{

    return m_ownedAttribute;
}


		std::shared_ptr<Subset<uml::Operation, uml::Feature
		,uml::NamedElement > >
 InterfaceImpl::getOwnedOperation() const
{

    return m_ownedOperation;
}


		std::shared_ptr<Subset<uml::Reception, uml::Feature
		,uml::NamedElement > >
 InterfaceImpl::getOwnedReception() const
{

    return m_ownedReception;
}


std::shared_ptr<uml::ProtocolStateMachine > InterfaceImpl::getProtocol() const
{

    return m_protocol;
}
void InterfaceImpl::setProtocol(std::shared_ptr<uml::ProtocolStateMachine> _protocol)
{
    m_protocol = _protocol;
}

		std::shared_ptr<Subset<uml::Interface, uml::Classifier /*Subset does not reference a union*/ > >
 InterfaceImpl::getRedefinedInterface() const
{

    return m_redefinedInterface;
}


//*********************************
// Union Getter
//*********************************
		std::shared_ptr<SubsetUnion<uml::Feature, uml::NamedElement > >
 InterfaceImpl::getFeature() const
{
	

	return m_feature;
}
std::shared_ptr<uml::Namespace > InterfaceImpl::getNamespace() const
{
	

	return m_namespace;
}
std::shared_ptr<uml::Element > InterfaceImpl::getOwner() const
{
	

	return m_owner;
}
		std::shared_ptr<SubsetUnion<uml::Property, uml::Feature > >
 InterfaceImpl::getAttribute() const
{
	

	return m_attribute;
}
		std::shared_ptr<Union<uml::Element> > InterfaceImpl::getOwnedElement() const
{
	

	return m_ownedElement;
}
		std::shared_ptr<SubsetUnion<uml::NamedElement, uml::Element
		,uml::NamedElement > >
 InterfaceImpl::getOwnedMember() const
{
	

	return m_ownedMember;
}
		std::shared_ptr<Union<uml::NamedElement> > InterfaceImpl::getMember() const
{
	

	return m_member;
}
		std::shared_ptr<Union<uml::RedefinableElement> > InterfaceImpl::getRedefinedElement() const
{
	

	return m_redefinedElement;
}


//*********************************
// Structural Feature Getter/Setter
//*********************************
boost::any InterfaceImpl::eGet(int featureID,  bool resolve, bool coreType) const
{
	switch(featureID)
	{
		case UmlPackage::CLASSIFIER_ATTRIBUTE:
			return getAttribute(); //5525
		case UmlPackage::NAMEDELEMENT_CLIENTDEPENDENCY:
			return getClientDependency(); //554
		case UmlPackage::CLASSIFIER_COLLABORATIONUSE:
			return getCollaborationUse(); //5526
		case ecore::EcorePackage::EMODELELEMENT_EANNOTATIONS:
			return getEAnnotations(); //550
		case UmlPackage::NAMESPACE_ELEMENTIMPORT:
			return getElementImport(); //5511
		case UmlPackage::CLASSIFIER_FEATURE:
			return getFeature(); //5524
		case UmlPackage::CLASSIFIER_GENERAL:
			return getGeneral(); //5527
		case UmlPackage::CLASSIFIER_GENERALIZATION:
			return getGeneralization(); //5528
		case UmlPackage::NAMESPACE_IMPORTEDMEMBER:
			return getImportedMember(); //5514
		case UmlPackage::CLASSIFIER_INHERITEDMEMBER:
			return getInheritedMember(); //5530
		case UmlPackage::CLASSIFIER_ISABSTRACT:
			return getIsAbstract(); //5531
		case UmlPackage::CLASSIFIER_ISFINALSPECIALIZATION:
			return getIsFinalSpecialization(); //5532
		case UmlPackage::REDEFINABLEELEMENT_ISLEAF:
			return getIsLeaf(); //5510
		case UmlPackage::NAMESPACE_MEMBER:
			return getMember(); //5515
		case UmlPackage::NAMEDELEMENT_NAME:
			return getName(); //555
		case UmlPackage::NAMEDELEMENT_NAMEEXPRESSION:
			return getNameExpression(); //556
		case UmlPackage::NAMEDELEMENT_NAMESPACE:
			return getNamespace(); //557
		case UmlPackage::INTERFACE_NESTEDCLASSIFIER:
			return getNestedClassifier(); //5538
		case UmlPackage::INTERFACE_OWNEDATTRIBUTE:
			return getOwnedAttribute(); //5539
		case UmlPackage::ELEMENT_OWNEDCOMMENT:
			return getOwnedComment(); //551
		case UmlPackage::ELEMENT_OWNEDELEMENT:
			return getOwnedElement(); //552
		case UmlPackage::NAMESPACE_OWNEDMEMBER:
			return getOwnedMember(); //5513
		case UmlPackage::INTERFACE_OWNEDOPERATION:
			return getOwnedOperation(); //5543
		case UmlPackage::INTERFACE_OWNEDRECEPTION:
			return getOwnedReception(); //5540
		case UmlPackage::NAMESPACE_OWNEDRULE:
			return getOwnedRule(); //5510
		case UmlPackage::TEMPLATEABLEELEMENT_OWNEDTEMPLATESIGNATURE:
			return getOwnedTemplateSignature(); //555
		case UmlPackage::CLASSIFIER_OWNEDUSECASE:
			return getOwnedUseCase(); //5533
		case UmlPackage::ELEMENT_OWNER:
			return getOwner(); //553
		case UmlPackage::PARAMETERABLEELEMENT_OWNINGTEMPLATEPARAMETER:
			return getOwningTemplateParameter(); //554
		case UmlPackage::TYPE_PACKAGE:
			return getPackage(); //5512
		case UmlPackage::NAMESPACE_PACKAGEIMPORT:
			return getPackageImport(); //5512
		case UmlPackage::CLASSIFIER_POWERTYPEEXTENT:
			return getPowertypeExtent(); //5529
		case UmlPackage::INTERFACE_PROTOCOL:
			return getProtocol(); //5541
		case UmlPackage::NAMEDELEMENT_QUALIFIEDNAME:
			return getQualifiedName(); //558
		case UmlPackage::CLASSIFIER_REDEFINEDCLASSIFIER:
			return getRedefinedClassifier(); //5535
		case UmlPackage::REDEFINABLEELEMENT_REDEFINEDELEMENT:
			return getRedefinedElement(); //5511
		case UmlPackage::INTERFACE_REDEFINEDINTERFACE:
			return getRedefinedInterface(); //5542
		case UmlPackage::REDEFINABLEELEMENT_REDEFINITIONCONTEXT:
			return getRedefinitionContext(); //5512
		case UmlPackage::CLASSIFIER_REPRESENTATION:
			return getRepresentation(); //5536
		case UmlPackage::CLASSIFIER_SUBSTITUTION:
			return getSubstitution(); //5537
		case UmlPackage::TEMPLATEABLEELEMENT_TEMPLATEBINDING:
			return getTemplateBinding(); //554
		case UmlPackage::PARAMETERABLEELEMENT_TEMPLATEPARAMETER:
			return getTemplateParameter(); //555
		case UmlPackage::CLASSIFIER_USECASE:
			return getUseCase(); //5534
		case UmlPackage::NAMEDELEMENT_VISIBILITY:
			return getVisibility(); //559
	}
	return boost::any();
}
